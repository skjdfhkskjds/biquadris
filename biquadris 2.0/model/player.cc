#include <vector>
#include <memory>
#include <string>
#include "player.h"
#include "board.h"
#include "level.h"

using namespace std;

struct Player::PlayerImpl
{
    unique_ptr<Level> lvl;
    unique_ptr<Board> board;
    vector<char> sequence;
    int turns;

    PlayerImpl(vector<char> sequence);
    ~PlayerImpl() = default;
    void newTurn(string effect="");
};

Player::PlayerImpl::PlayerImpl(vector<char> sequence) : lvl{new Level}, board{new Board}, sequence{sequence}, turns{0} {}

void Player::PlayerImpl::newTurn(string effect = "")
{

}

Player::Player(vector<char> sequence) : impl{new Player::PlayerImpl{sequence}} {}

Player::~Player() = default;

vector<char> Player::getState()
{
    // return impl->board.getState();
}
