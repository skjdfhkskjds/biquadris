#include <vector>
#include <memory>
#include <string>
#include <map>
#include "player.h"
#include "board.h"
#include "heavy.h"
#include "blind.h"
#include "force.h"
#include "level.h"

using namespace std;

struct Player::PlayerImpl
{
    shared_ptr<Board> board;
    vector<char> sequence;
    int turns, score, lvl;
    map<string, bool> effects;

    PlayerImpl(vector<char> sequence, int startLvl);
    ~PlayerImpl() = default;

    void playTurn(unique_ptr<AbstractBoard> tempBoard);
};

Player::PlayerImpl::PlayerImpl(vector<char> sequence, int startLvl) : sequence{sequence}, turns{0}, lvl{startLvl}, effects{{"heavy", false}, {"blind", false}, {"force", false}} 
{
    // init board in here
    // requires: level, currBlock, nextBlock
}

void Player::PlayerImpl::playTurn(unique_ptr<AbstractBoard> tempBoard)
{
    // continue running until user inputs "done"
}

Player::Player(vector<char> sequence, int startLvl) : impl{new Player::PlayerImpl{sequence, startLvl}} {}

Player::~Player() = default;

vector<char> Player::getState()
{
    return impl->board->getState();
}

unique_ptr<AbstractBoard> Player::apply()
{
    unique_ptr<AbstractBoard> effectBoard = make_unique<AbstractBoard>(impl->board);
    for (auto & [key, val] : impl->effects)
    {
        if (!val) continue;

        if (key == "heavy")
        {
            effectBoard = make_unique<Heavy>(move(effectBoard), 2);
        }
        else if (key == "blind")
        {
            effectBoard = make_unique<Blind>(move(effectBoard));
        }
        else if (key == "force")
        {
            char c;
            // ask for more input for which char to force
            effectBoard = make_unique<Force>(move(effectBoard), c);
        }
    }
}

void Player::resetEffects()
{
    for (auto &e : impl->effects)
    {
        e.second = false;
    }
}

void Player::setEffect(string effect)
{
    if (impl->effects.count(effect) != 0)
    {
        impl->effects[effect] = true;
    }
}

void Player::playTurn()
{
    impl->playTurn();   
}

char Player::getNext() {
    return impl->board->getNext();
}

int Player::getScore() {
    return impl->score;
}

void Player::levelUp()
{

}

void Player::levelDown()
{

}

int Player::getLevel() {
    return impl->lvl;
}
