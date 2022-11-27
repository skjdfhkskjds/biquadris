#ifndef _PLAYER_
#define _PLAYER_

#include <memory>

class Player
{
    class PlayerImpl;
    std::unique_ptr<PlayerImpl> pImpl;
public:
    Player() noexcept;
    void levelUp() noexcept;
    void levelDown() noexcept;
    void display() noexcept;
};

#endif
