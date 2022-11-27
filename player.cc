#include <memory>
#include "player.h"

struct Player::PlayerImpl
{
    // Board board;
    int level;

    PlayerImpl() : level{0} {}
};

Player::Player() : pImpl{new Player::PlayerImpl} {}

void Player::levelUp()
{
    pImpl->level++;
}

void Player::levelDown()
{
    pImpl->level--;
}

// implement display
void Player::display()
{

}