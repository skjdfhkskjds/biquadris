#include <memory>
#include <vector>
#include <string>
#include "board.h"
#include "boardstate.h"
#include "block.h"
#include "level.h"

using namespace std;

struct Board::BoardImpl
{
    unique_ptr<BoardState> boardState;
    unique_ptr<Block> currBlock, nextBlock;
    unique_ptr<Level> lvl;

    BoardImpl(unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock, unique_ptr<Level> lvl);
    ~BoardImpl() = default;
};

Board::BoardImpl::BoardImpl(unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock, unique_ptr<Level> lvl) : boardState{new BoardState}, currBlock{move(currBlock)}, nextBlock{move(nextBlock)}, lvl{move(lvl)} {}

Board::Board(unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock, unique_ptr<Level> lvl) : impl{new Board::BoardImpl{move(currBlock), move(nextBlock), move(lvl)}} {}

Board::~Board() = default;

unique_ptr<Block> Board::getBlock(char c)
{
    // to be implemented
}

void Board::setBlock(unique_ptr<Block> block)
{
    impl->currBlock = move(block);
}

vector<char> Board::getState()
{
    // to be implemented
    vector<char> outState = impl->boardState->getState();
    return outState;
}

void Board::counterClockwise()
{

}

void Board::clockwise()
{

}

void Board::left()
{

}

void Board::right()
{

}

void Board::down()
{

}

char Board::getNextBlockChar() {
    return impl->boardState->getNextBlockChar();
}