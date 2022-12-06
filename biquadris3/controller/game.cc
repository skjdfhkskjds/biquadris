#include <iostream>
#include <fstream>
#include "game.h"
#include "../common/exceptions.h"

using namespace std;

Game::Game(int seed, int startLvl, vector<string> sequences) : seed{seed}, startLvl{startLvl}, interpreter{}
{
    turn = 0;
    vector<vector<char>> seqs;
    int len = sequences.size();
    for (int i = 0; i < len; i++)
    {
        vector<char> seq;
        try
        {
            seq = read(sequences[i]);
        }
        catch (file_not_found &e)
        {
            seq = read(e.getDefault(i));
            cerr << e.what() << endl;
        }
        seqs.emplace_back(seq);
    }
    players.emplace_back(make_unique<Player>(seqs[0], seed, startLvl));
    players.emplace_back(make_unique<Player>(seqs[1], seed, startLvl));
}

vector<std::unique_ptr<Player>> Game::getPlayers()
{
    return players;
};

vector<char> Game::read(string s)
{
    vector<char> sequence;
    ifstream file{s};
    if (file.is_open())
    {
        char c;
        while (file >> c)
        {
            if (file.fail())
            {
                file.clear();
                file.ignore();
                continue;
            }
            sequence.emplace_back(c);
        }
    }
    else
    {
        throw file_not_found{s};
    }
    return sequence;
}

vector<vector<char>> Game::getState()
{
    vector<vector<char>> out;
    out.emplace_back(players[0]->getState());
    out.emplace_back(players[1]->getState());
    return out;
}

int Game::run()
{
    // gamestate vars
    int turns = 0;
    // placeholder bool
    bool isFinished;
    while (!isFinished)
    {
        playTurn();
    }
    // string input;
    // while (cin >> input)
    // {
    //     if (cin.fail())
    //     {
    //         cin.ignore();
    //         cin.clear();
    //         continue;
    //     }

    //     interpreter.interpret(input);
    // }
}

void Game::playTurn()
{
    map<string, int> gameCommands{
        {"norandom", 0},
        {"random", 1},
        {"sequence", 2},
        {"restart", 3},
        {"blind", 4},
        {"heavy", 5},
        {"force", 6}
    };

    int p = turn % 2;
    players[p]->apply();
    string input;
    while (cin >> input && input != "drop")
    {
        vector<string> commands;
        // standard processing includes pushing the command itself to commands
        commands = interpreter.interpret(input); // interpret "preprocesses" the command
        for (string command : commands)
        { // assume that commands in input file are all player commands
            if (command == "drop")
            {
                // do some stuff to drop
                break;
            }
            string file;
            int cmd = gameCommands[command];
            if (cmd == 0)
            { // norandom
             
                cin >> file;
                ifstream ifs{file};
                if (!ifs.good())
                {
                    throw file_not_found(file);
                }
                vector<char> blockSeq = read(file);
                players[p]->setSequence(blockSeq); //
                // find a way to set lvl isRandom to false
            }
            else if (cmd == 1)
            {
                //need setRandom
                //players[p]->setRandom(true);
            }
            else if (cmd == 2)
            {
                // sequence
                cin >> file;
                ifstream ifs{file};
                if (!ifs.good())
                {
                    throw file_not_found(file);
                }
                vector<char> seq = read(file);
                int len = seq.size();
                for (int i = 0; i < len; i++)
                {
                    commands.emplace_back(seq[i]);
                }
                // sequence(file);
            }
            else if (cmd == 3)
            {
                // reset all game state variables
                turn = 0;
                players[0] = make_unique<Player>(seqs[0], seed, startLvl);
                players[1] = make_unique<Player>(seqs[0], seed, startLvl);
                //not sure if this requires change to sequences
            }
            else
            {
                players[p]->playTurn(command);
                // player cmds
            }
        }
    }
    players[p]->playTurn("drop");
    // check rowscleared to use effect
    // placeholder bool
    bool effectAvailable;
    if (effectAvailable) 
    {
        cout<<"Select an effect : Blind / Heavy / Force"<<endl;
        cin >> input;
        // check if effect is valid? (check if input == "blind" or "force" or "heavy")
        players[p + 1 % 2]->setEffect(input);
    }
    players[p]->resetEffects();
    // no method to update player score
    players[p]->setup();
    turn++;
}

// call on players[p]
// apply()
// get currBlock
// read in commands until drop
// check rows cleared somehow with boardstate
// if effect command, call other players setEffect(effect command)
// resetEffects()
// update score
// call board->setup()

