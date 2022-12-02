#ifndef _GAME_
#define _GAME_

#include <memory>
#include <vector>
#include <string>
#include "../model/player.h"
#include "../model/subject.h"

class Game : public Subject
{
    std::unique_ptr<Player> p1, p2;
    std::vector<std::vector<char>> sequences;

    std::vector<char> read(std::string sequence); 

public:
    Game(int seed, int startLvl, std::vector<std::string> sequences);

    int run(); // runs the game, returns 0 if p1 wins, if p2 wins

    std::vector<std::vector<char>> getState() override; // returns a vector of both player's states

};

#endif
