#include <memory>
#include <vector>
#include <string>
#include "board.h"
#include "boardstate.h"

using namespace std;

struct Board::BoardImpl
{
    static const int width = 11;
    static const int height = 18;
    unique_ptr<BoardState> boardState;

    BoardImpl();
    ~BoardImpl() = default;
};

Board::BoardImpl::BoardImpl() : boardState{new BoardState} {}

Board::Board() : impl{new BoardImpl} {}

Board::~Board() = default;

// returns a boardstate representing 
vector<char> Board::applyEffect(string effect)
{
    // to be implemented
}

vector<char> Board::getState()
{
    vector<char> outState = impl->boardState->getState();
    // apply effects first
    return outState;
}
