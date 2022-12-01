#ifndef _GAME_
#define _GAME_

#include <memory>
#include <string>
#include <vector>
#include "player.h"

class Game
{
    class GameImpl;
    std::unique_ptr<GameImpl> impl;

public:
    Game(std::vector<std::string> sequences, int seed, int startLvl);
    void runGame();
};

#endif
