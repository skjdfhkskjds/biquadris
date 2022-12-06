#include <iostream>
#include <fstream>
#include "game.h"
#include "../common/exceptions.h"

using namespace std;

Game::Game(int seed, int startLvl, vector<string> sequences) : seed{seed}, startLvl{startLvl}, interpreter{}
{
    turn = 0;
    highscore = 0;
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
    // placeholder bool
    bool isFinished;
    while (!isFinished)
    {
        playTurn();
    }
    //check for player loss
}

void Game::playTurn()
{
    map<string, int> gameCommands{
        {"norandom", 0},
        {"random", 1},
        {"sequence", 2},
        {"restart", 3},
    };

    int p = turn % 2;
    players[p]->apply();
    cout << "Player " << p << "'s turn." << endl;
    string input;
    bool dropped = false;
    while (cin >> input && !dropped)
    {
        vector<string> commands;
        // standard processing includes pushing the command itself to commands
        commands = interpreter.interpret(input); // interpret "preprocesses" the command
        for (string command : commands)
        { // assume that commands in input file are all player commands
            if (command == "drop") 
            {
                players[p]->playTurn("drop");
                dropped = true;
                break;
            }
            string file;
            int cmd = gameCommands[command];
            if (cmd == 0) // norandom
            {
                cin >> file;
                ifstream ifs{file};
                if (!ifs.good())
                {
                    throw file_not_found(file);
                }
                vector<char> blockSeq = read(file);
                players[p]->setSequence(blockSeq);
                players[p]->setRandom(false);
            }
            else if (cmd == 1)
            { // random
                players[p]->setRandom(true);
            }
            else if (cmd == 2)
            { // sequence
                cin >> file;
                ifstream ifs{file};
                if (!ifs.good())
                {
                    throw file_not_found(file);
                }
                if (ifs.is_open())
                {
                    string newCmd;
                    while (ifs >> newCmd)
                    {
                        if (ifs.fail())
                        {
                            ifs.clear();
                            ifs.ignore();
                            continue;
                        }
                        commands.emplace_back(newCmd);
                    }
                }
            }
            else if (cmd == 3)
            {
                // restart
                turn = 0;
                players[0] = make_unique<Player>(seqs[0], seed, startLvl);
                players[1] = make_unique<Player>(seqs[1], seed, startLvl);
                // does not change highscore
            }
            else // player cmds
            {
                players[p]->playTurn(command);

            }
        }
    }
    // check rowscleared to use effect
    // placeholder bool
    bool effectAvailable;
    if (effectAvailable)
    {
        cout << "Effect available" << endl;
        cout << "Select an effect : blind / heavy / force" << endl;
        cin >> input;
        if (input == "blind" || input == "heavy") {
            players[p + 1 % 2]->setEffect(input);
        } else if (input == "force") {
            cout << "Enter a block" << endl; //check if real block?
            char c;
            cin >> c; 
            players[p + 1 % 2]->setForcedChar(c);
            players[p + 1 % 2]->setEffect(input);
        }
        
    }
    int currScore = players[p]->getScore();
    cout << "Current Score: " <<  currScore << endl;
    if (currScore > highscore) {
        highscore = currScore;
        cout << "New Highscore!" << endl;
    }
    players[p]->resetEffects();
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
