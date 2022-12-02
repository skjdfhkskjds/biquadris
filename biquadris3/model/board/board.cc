#include <memory>
#include "board.h"
#include "../levels/level.h"
#include "../levels/levelzero.h"
#include "../levels/levelone.h"
#include "../levels/leveltwo.h"
#include "../levels/levelthree.h"
#include "../levels/levelfour.h"
#include "../blocks/block.h"
#include "../blocks/iblock.h"
#include "../blocks/jblock.h"
#include "../blocks/lblock.h"
#include "../blocks/oblock.h"
#include "../blocks/sblock.h"
#include "../blocks/tblock.h"
#include "../blocks/zblock.h"

#include "boardstate.h"

using namespace std;

struct Board::BoardImpl
{
    unique_ptr<Level> lvl;
    unique_ptr<BoardState> state;
    unique_ptr<Block> currBlock, nextBlock;

    unique_ptr<Block> makeBlock(char c);    // makes block of type c
    void setBlock(unique_ptr<Block> block); // sets currBlock to block

    BoardImpl(int startLvl, int seed);
};

Board::BoardImpl::BoardImpl(int startLvl, int seed)
{
    lvl = make_unique<Level>(startLvl, seed);
    switch(startLvl)
    {
        case 0:
        {
            lvl = make_unique<LevelZero>(seed);
            break;
        }
        case 1:
        {
            lvl = make_unique<LevelOne>(seed);
            break;
        }
        case 2:
        {
            lvl = make_unique<LevelTwo>(seed);
            break;
        }
        case 3:
        {
            lvl = make_unique<LevelThree>(seed);
            break;
        }
        case 4:
        {
            lvl = make_unique<LevelFour>(seed);
            break;
        }
    }
    currBlock = move(makeBlock(lvl->generateBlock()));
    nextBlock = move(makeBlock(lvl->generateBlock()));
}

unique_ptr<Block> Board::BoardImpl::makeBlock(char c)
{
    unique_ptr<Block> newBlock;
    switch(c)
    {
        case 'I':
        {
            newBlock = make_unique<IBlock>(lvl->getLvl());
            break;
        }
        case 'J':
        {
            newBlock = make_unique<JBlock>(lvl->getLvl());
            break;
        }
        case 'L':
        {
            newBlock = make_unique<LBlock>(lvl->getLvl());
            break;
        }
        case 'O':
        {
            newBlock = make_unique<OBlock>(lvl->getLvl());
            break;
        }
        case 'S':
        {
            newBlock = make_unique<SBlock>(lvl->getLvl());
            break;
        }
        case 'Z':
        {
            newBlock = make_unique<ZBlock>(lvl->getLvl());
            break;
        }
        case 'T':
        {
            newBlock = make_unique<TBlock>(lvl->getLvl());
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

Board::Board(int startLvl, int seed) : AbstractBoard{nullptr}, impl{make_unique<BoardImpl>(startLvl, seed)} {}

unique_ptr<Block> Board::makeBlock(char c) { impl->makeBlock(c); }

void Board::setBlock(unique_ptr<Block> block) { impl->setBlock(move(block)); }

vector<char> Board::getState() { return impl->state->getState(); }

char Board::getNext() { return impl->nextBlock->getChar(); }

void Board::counterClockwise()
{
    impl->currBlock = impl->state->counterClockwise(move(impl->currBlock));
}

void Board::clockwise()
{
    impl->currBlock = impl->state->clockwise(move(impl->currBlock));
}

void Board::left()
{
    impl->currBlock = impl->state->left(move(impl->currBlock));
}

void Board::right()
{
    impl->currBlock = impl->state->right(move(impl->currBlock));
}

void Board::down()
{
    impl->currBlock = impl->state->down(move(impl->currBlock));
}
