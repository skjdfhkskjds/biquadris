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

#define toUpper(c) (char)(('a' <= c && c <= 'z') ? (c - 'a' + 'A') : c)

using namespace std;

struct Player::PlayerImpl
{
    vector<char> seq;
    static map<string, int> playerCommands;
    unique_ptr<AbstractBoard> board;
    int lvl, turns, score;
    map<string, bool> effects;
    char forcedBlock;
    vector<char> getState();

    PlayerImpl(vector<char> seq, int startLvl, int seed);
    ~PlayerImpl() = default;

    void apply();                         // applies all effects onto board
};

Player::PlayerImpl::PlayerImpl(vector<char> seq, int startLvl, int seed) : seq{seq}, lvl{startLvl}, turns{0}, score{0}, effects{{"heavy", false}, {"blind", false}, {"force", false}}
{
    board = make_unique<Board>(startLvl, seed, seq);
}

vector<char> Player::PlayerImpl::getState() {
    return board->getState();
}

vector<char> Player::getState()  {
    return impl->getState();
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
            // MAKE ERROR CHECKING AND GET USER INPUT FOR c
            board = make_unique<Force>(move(board), forcedBlock);
        }
    }
}

// play turn must call apply then create a sequence to read and execute user commands

Player::Player(vector<char> seq, int startLvl, int seed) : impl{make_unique<Player::PlayerImpl>(seq, startLvl, seed)} {}

Player::~Player() = default;

int Player::getLevel() { return impl->lvl; }

int Player::getScore() { return impl->score; }

char Player::getNext() { return impl->board->getNext(); }

void Player::apply() { impl->apply(); }

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

void Player::setEffect(string effect)
{
    if (impl->effects.count(effect) != 0)
    {
        impl->effects[effect] = true;
    }
}

void Player::setForcedChar(char c) { impl->forcedBlock = c; }

void Player::levelUp()
{
    if (impl->lvl == MAX_LEVEL)
        throw invalid_level{MAX_LEVEL};
    impl->lvl++;
    impl->board->setLevel(impl->lvl);
}

void Player::levelDown()
{
    if (impl->lvl == MIN_LEVEL)
        throw invalid_level{MIN_LEVEL};
    impl->lvl--;
    impl->board->setLevel(impl->lvl);
}

void Player::playTurn(int cmd)
{
    switch (cmd)
    {
    case 0:
        impl->board->left();
        break;
    case 1:
        impl->board->right();
        break;
    case 2:
        impl->board->down();
        break;
    case 3:
        impl->board->clockwise();
        break;
    case 4:
        impl->board->counterClockwise();
        break;
    case 5:
        impl->score += impl->board->drop();
        break;
    case 6:
        levelUp();
        break;
    case 7:
        levelDown();
        break;
    // add more cases later for replacing blocks
    default:
        break;
    }
}

void Player::setSequence(vector<char> newSeq) 
{ 
    impl->seq = newSeq;
    impl->board->setSequence(newSeq);
}

void Player::setRandom(bool isRandom) 
{
    impl->board->setRandom(isRandom);
}
void Player::setup() { impl->board->setup(); }


