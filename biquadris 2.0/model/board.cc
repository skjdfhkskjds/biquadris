#include <memory>
#include <vector>
#include <string>
#include "abstractboard.h"
#include "board.h"
#include "boardstate.h"
#include "block.h"
#include "level.h"

using namespace std;

struct Board::BoardImpl
{
    unique_ptr<BoardState> boardState;
    unique_ptr<Level> lvl;

    BoardImpl(unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock, unique_ptr<Level> lvl);
    ~BoardImpl() = default;
};

Board::BoardImpl::BoardImpl(unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock, unique_ptr<Level> lvl) : boardState{new BoardState{move(currBlock), move(nextBlock)}}, lvl{move(lvl)} {}

Board::Board(unique_ptr<Level> lvl, unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock) : impl{new Board::BoardImpl{move(currBlock), move(nextBlock), move(lvl)}} {}

Board::~Board() = default;

unique_ptr<Block> Board::getBlock(char c)
{
    // to be implemented
}

void Board::setBlock(unique_ptr<Block> block)
{
    impl->boardState->setBlock(move(block));
}

vector<char> Board::getState()
{
    // to be implemented
    vector<char> outState = impl->boardState->getState();
    return outState;
}

void Board::counterClockwise()
{
    impl->boardState->counterClockwise();
}

void Board::clockwise()
{
    impl->boardState->clockwise();
}

void Board::left()
{
    impl->boardState->left();
}

void Board::right()
{
    impl->boardState->right();
}

void Board::down()
{
    impl->boardState->down();
}

char Board::getNext() {
    return impl->boardState->getNext();
}
