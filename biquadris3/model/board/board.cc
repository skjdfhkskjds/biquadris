
#include <memory>
#include "board.h"
#include "../levels/level.h"
#include "boardstate.h"

using namespace std;

struct Board::BoardImpl
{
    unique_ptr<Level> lvl;
    unique_ptr<BoardState> state;
    unique_ptr<Block> currBlock, nextBlock;

    unique_ptr<Block> makeBlock(char c);    // makes block of type c
    void setBlock(unique_ptr<Block> block); // sets currBlock to block

    BoardImpl(int startLvl);
};

Board::BoardImpl::BoardImpl(int startLvl)
{
    lvl = make_unique<Level>(startLvl);
    char curr = lvl->generateBlock();
    char next = lvl->generateBlock();
    currBlock = move(makeBlock(curr));
    nextBlock = move(makeBlock(next));
}

unique_ptr<Block> Board::BoardImpl::makeBlock(char c)
{
    unique_ptr<Block> newBlock;
    switch(c)
    {
        case 'I':
        {
            newBlock = make_unique<IBlock>();
            break;
        }
        case 'J':
        {
            newBlock = make_unique<JBlock>();
            break;
        }
        case 'L':
        {
            newBlock = make_unique<LBlock>();
            break;
        }
        case 'O':
        {
            newBlock = make_unique<OBlock>();
            break;
        }
        case 'S':
        {
            newBlock = make_unique<SBlock>();
            break;
        }
        case 'Z':
        {
            newBlock = make_unique<ZBlock>();
            break;
        }
        case 'T':
        {
            newBlock = make_unique<TBlock>();
            break;
        }
        default:
            // handle c isn't a block
            break;
    }
    return move(newBlock);
}

void Board::BoardImpl::setBlock(unique_ptr<Block> block)
{
    currBlock = move(block);
}

Board::Board(int startLvl) : AbstractBoard{nullptr}, impl{make_unique<BoardImpl>(startLvl)} {}

unique_ptr<Block> Board::makeBlock(char c) { impl->makeBlock(c); }

void Board::setBlock(unique_ptr<Block> block) { impl->setBlock(move(block)); }

vector<char> Board::getState() { return impl->state->state; }

char Board::getNext() { return impl->nextBlock->getChar(); }

void Board::counterClockwise()
{
    impl->state->counterClockwise();
}

void Board::clockwise()
{
    impl->state->clockwise();
}

void Board::left()
{
    impl->state->left();
}

void Board::right()
{
    impl->state->right();
}

void Board::down()
{
    impl->state->down();
}
