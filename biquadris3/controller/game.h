#ifndef _GAME_
#define _GAME_

#include <memory>
#include <vector>
#include <string>
#include "commands.h"
#include "../model/player.h"
#include "../model/subject.h"

class Game : public Subject
{
    std::vector<std::unique_ptr<Player>> players;
    Commands interpreter;
    int turn;

    std::vector<char> read(std::string sequence); // reads in the file sequence and produces it as a char array

public:
    Game(int seed, int startLvl, std::vector<std::string> sequences);
    ~Game() = default;

    vector<std::unique_ptr<Player>> getPlayers();
    
    int run(); // runs the game, returns 0 if p1 wins, if p2 wins

    void playTurn(); //plays one turn for one player

    std::vector<std::vector<char>> getState() override; // returns a vector of both player's states
};

#endif
