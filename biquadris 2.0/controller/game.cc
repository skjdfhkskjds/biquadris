// #include <iostream>
#include <fstream>
#include <memory>
#include "game.h"

using namespace std;

struct Game::GameImpl
{
    unique_ptr<Player> p1;
    unique_ptr<Player> p2;
    int seed, startLvl;


    GameImpl(vector<string> sequences, int seed, int startLvl);
    ~GameImpl() = default;
};

Game::GameImpl::GameImpl(vector<string> sequences, int seed, int startLvl) : seed{seed}, startLvl{startLvl} 
{
    vector<char> s1, s2;
    for (auto s : sequences)
    {
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
                
            }
        }
    }
    p1 = make_unique<Player>();
}

Game::Game(vector<string> sequences, int seed, int startLvl) : impl{new GameImpl{sequences, seed, startLvl}} {}

void Game::runGame()
{
    // implement this
}
