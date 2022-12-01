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

    PlayerImpl(vector<char> sequence, int startLvl);
    ~PlayerImpl() = default;
    void newTurn(string effect="");
};

Player::PlayerImpl::PlayerImpl(vector<char> sequence, int startLvl) : board{new Board}, sequence{sequence}, turns{0}
{
    lvl = make_unique<Level>(startLvl);
}

void Player::PlayerImpl::newTurn(string effect = "")
{

}

Player::Player(vector<char> sequence, int startLvl) : impl{new Player::PlayerImpl{sequence, startLvl}} {}

Player::~Player() = default;

vector<char> Player::getState()
{
    // return impl->board.getState();
}
