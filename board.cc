#include "board.h"
#include "block.h"
#include "boardstate.h"
#include <memory>

using namespace std;

struct Board::BoardImpl
{
    int ticksSinceClear;
    unique_ptr<BoardState> boardState;
};

Board::Board() : pImpl{new BoardImpl} {}

Board::~Board() {}

void Board::getState()
{

}

void Board::addBlock(Block &block)
{

}