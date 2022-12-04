#include <iostream>
#include <map>
#include <string>
#include "player.h"
#include "board/abstractboard.h"
#include "board/board.h"
#include "../common/exceptions.h"
#include "effects/blind.h"
#include "effects/force.h"
#include "effects/heavy.h"

#define MAX_LEVEL 4
#define MIN_LEVEL 0

using namespace std;

struct Player::PlayerImpl
{
    unique_ptr<AbstractBoard> board;
    int turns, lvl, score;
    map<string, bool> effects;
    vector<char> seq;

    PlayerImpl(vector<char> seq, int startLvl, int seed);
    ~PlayerImpl() = default;

    void apply();                         // applies all effects onto board
    unique_ptr<AbstractBoard> playTurn(); // plays a turn
};

Player::PlayerImpl::PlayerImpl(vector<char> seq, int startLvl, int seed) : seq{seq}, lvl{startLvl}, turns{0}, score{0}, effects{{"heavy", false}, {"blind", false}, {"force", false}}
{
    board = make_unique<Board>(startLvl, seed);
}

void Player::PlayerImpl::apply()
{
    for (auto const &e : effects)
    {
        // if not true, skip
        if (!e.second)
            continue;

        if (e.first == "heavy")
        {
            board = make_unique<Heavy>(move(board), 2);
        }
        else if (e.first == "blind")
        {
            board = make_unique<Blind>(move(board));
        }
        else if (e.first == "force")
        {
            char c;
            // MAKE ERROR CHECKING AND GET USER INPUT FOR c
            board = make_unique<Force>(move(board), c);
        }
    }
}

// play turn must call apply then create a sequence to read and execute user commands
unique_ptr<AbstractBoard> Player::PlayerImpl::playTurn()
{
    // update score
}

Player::Player(vector<char> seq, int startLvl, int seed) : impl{make_unique<Player::PlayerImpl>(seq, startLvl, seed)} {}

void Player::playTurn() { impl->playTurn(); }

int Player::getLevel() { return impl->lvl; }

int Player::getScore() { return impl->score; }

char Player::getNext() { return impl->board->getNext(); }

unique_ptr<AbstractBoard> Player::apply() { impl->apply(); }

void Player::resetEffects()
{
    // for each effect, set it to false
    for (auto &e : impl->effects)
    {
        e.second = false;
    }

    // reset the board component to only contain the base, non-effect decorated board
    while (impl->board->component != nullptr)
    {
        impl->board = move(impl->board->component);
    }
}

void Player::setEffect(std::string effect)
{
    if (impl->effects.count(effect) != 0)
    {
        impl->effects[effect] = true;
    }
}

void Player::levelUp()
{
    if (impl->lvl == MAX_LEVEL) throw invalid_level{MAX_LEVEL};
    impl->lvl++;
    impl->board->setLevel(impl->lvl);
}

void Player::levelDown()
{
    if (impl->lvl == MIN_LEVEL) throw invalid_level{MIN_LEVEL};
    impl->lvl--;
    impl->board->setLevel(impl->lvl);
}
