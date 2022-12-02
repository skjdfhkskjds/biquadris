#include <fstream>
#include "game.h"
#include "../misc/exceptions.h"

using namespace std;

Game::Game(int seed, int startLvl, std::vector<std::string> sequences)
{
    Game::sequences.emplace_back(read(sequences[0]));
    Game::sequences.emplace_back(read(sequences[1]));

    // make players
    // uses seed and startLvl to make Level in Player
}

// reads in the file "s" and outputs a vector containing its contents
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

int Game::run()
{
    // gamestate vars
    int turns = 0;

    // 
}
