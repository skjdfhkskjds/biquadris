#ifndef _PLAYER_
#define _PLAYER_

#include <memory>
#include <vector>
#include "board/abstractboard.h"

class Player final
{
    class PlayerImpl;
    std::unique_ptr<PlayerImpl> impl;

public:
    Player(std::vector<char> seq, int startLvl, int seed);
    ~Player();

    void playTurn(); // plays a turn

    // accessor methods
    std::vector<char> getState(); // returns the char represented boardstate
    int getLevel();               // returns the player's level
    int getScore();               // returns the player's score
    char getNext();               // returns the player's next block

    // effect modifiers
    std::unique_ptr<AbstractBoard> apply(); // returns a board with the effects applied
    void resetEffects();                    // resets the player state and removes all effects
    void setEffect(std::string effect);     // sets effect for the player

    // level modifiers
    void levelUp();   // increases the level
    void levelDown(); // decreases the level
};

#endif
