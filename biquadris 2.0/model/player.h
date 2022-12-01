#ifndef _PLAYER_
#define _PLAYER_

#include <memory>
#include <string>
#include <vector>
#include "subject.h"

class Player final : public Subject
{
    class PlayerImpl;
    std::unique_ptr<PlayerImpl> impl;

public:
    Player(std::vector<char> sequence, int startLvl);
    ~Player();

    void newTurn(std::string effect="");

    std::vector<char> getState() override;
    char getNextBlockChar();
    int getScore();
    int getLevel();
};

#endif
