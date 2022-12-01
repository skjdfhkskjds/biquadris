#ifndef _GAME_
#define _GAME_

#include <memory>
#include <string>
#include <vector>
#include "player.h"

class Game final
{
    class GameImpl;
    std::unique_ptr<GameImpl> impl;

public:
    Game(std::vector<std::string> sequences, int seed, int startLvl); // strong guarantee of exception safety
    void runGame();
};

#endif
