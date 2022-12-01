#include <iostream>
#include <fstream>
#include <memory>
#include "game.h"
#include "../misc/exceptions.h"

using namespace std;

struct Game::GameImpl
{
    vector<unique_ptr<Player>> players;
    int seed, startLvl;

    GameImpl(vector<string> sequences, int seed, int startLvl);
    ~GameImpl() = default;

private:
    vector<char> readSequence(string s);
};

// reads in the file "s" and outputs a vector containing its contents
vector<char> readSequence(string s)
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
}

Game::GameImpl::GameImpl(vector<string> sequences, int seed, int startLvl) : seed{seed}, startLvl{startLvl}
{
    // creates two players
    for (int i = 0; i < 2; i++)
    {
        vector<char> s;
        // makes vector sequence if file exists
        try
        {
            s = readSequence(sequences[i]);
        }
        catch(file_not_found& e)
        {
            cerr << e.what() << endl;
            s = readSequence(e.getDefault(i));
        }
        players.emplace_back(make_unique<Player>(s));
    }
}

Game::Game(vector<string> sequences, int seed, int startLvl) : impl{new Game::GameImpl{sequences, seed, startLvl}} {}

void Game::runGame()
{
    // implement this
}
