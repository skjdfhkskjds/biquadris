#include "board.h"
#include "block.h"
#include "boardstate.h"
#include <memory>

using namespace std;

struct Board::BoardImpl
{
    int ticksSinceClear;
    int turns;
    unique_ptr<BoardState> boardState;

    BoardImpl() : ticksSinceClear{0}, turns{0} {}
};

Board::Board() : pImpl{new BoardImpl} {}

Board::~Board() {}

void Board::getState()
{

}

void Board::addBlock(Block &block)
{

}