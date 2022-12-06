#include <iostream>
#include <fstream>
#include "game.h"
#include "../common/exceptions.h"

using namespace std;

Game::Game(int seed, int startLvl, vector<string> sequences) : interpreter{}
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
        catch(file_not_found& e)
        {
            seq = read(e.getDefault(i));
            cerr << e.what() << endl;
        }
        seqs.emplace_back(seq);
    }
    players.emplace_back(make_unique<Player>(seqs[0], seed, startLvl));
    players.emplace_back(make_unique<Player>(seqs[1], seed, startLvl));
}

vector<std::unique_ptr<Player>> Game::getPlayers() {
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

    while (!isFinished)
    {
        players[turns % 2]->playTurn();
    }
    string input;
    while (cin >> input)
    {
        if (cin.fail())
        {
            cin.ignore();
            cin.clear();
            continue;
        }

        interpreter.interpret(input);
    }
}

void Game::playTurn()
{
    int p = turn % 2;
    //call on players[p]

    //apply()
    //get currBlock
    //read in commands until drop
    //check rows cleared somehow with boardstate
    //if effect command, call other players setEffect(effect command)
    //resetEffects()
    //update score
    //call board->setup()
    players[p]->apply();
    string input;
    while (cin >> input)
    {
        if (input == "drop")   {
            players[p]drop();
        }
        string command = interpreter.stringInterpret(input);
        

    }
    turn++;
    
}
