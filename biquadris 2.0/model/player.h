#ifndef _PLAYER_
#define _PLAYER_

#include <memory>
#include <string>
#include <vector>
#include "subject.h"
#include "abstractboard.h"

class Player final : public Subject
{
    class PlayerImpl;
    std::unique_ptr<PlayerImpl> impl;

public:
    Player(std::vector<char> sequence, int startLvl);
    ~Player();

    void playTurn(); // plays a turn

    std::vector<char> getState() override; // returns the player's board state

    std::unique_ptr<AbstractBoard> apply(); // returns a new board decorated with effects
    void resetEffects();                    // resets bools at the end of the turn
    void setEffect(std::string effect);     // sets an effect for player

    char getNext(); // returns the char representing player's next block
    int getScore(); // returns the player's score

    void levelUp();   // increases the level by 1
    void levelDown(); // decreases the level by 1
    int getLevel();   // returns the level
};

#endif
