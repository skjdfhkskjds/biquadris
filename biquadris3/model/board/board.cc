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
    int seed;
    char nextBlock;
    unique_ptr<Level> lvl;
    unique_ptr<BoardState> state;
    shared_ptr<Block> currBlock;

    shared_ptr<Block> makeBlock(char c);       // makes block of type c
    unique_ptr<Level> makeLevel(int startLvl); // makes a lvl level

    void setBlock(shared_ptr<Block> &block); // sets currBlock to block
    void setLevel(int level);                // sets lvl to level

    BoardImpl(int startLvl, int seed);
};

unique_ptr<Level> Board::BoardImpl::makeLevel(int startLvl)
{
    unique_ptr<Level> level;
    switch (startLvl)
    {
    case 0:
    {
        level = make_unique<LevelZero>(seed);
        break;
    }
    case 1:
    {
        level = make_unique<LevelOne>(seed);
        break;
    }
    case 2:
    {
        level = make_unique<LevelTwo>(seed);
        break;
    }
    case 3:
    {
        level = make_unique<LevelThree>(seed);
        break;
    }
    case 4:
    {
        level = make_unique<LevelFour>(seed);
        break;
    }
    }
    return move(level);
}

Board::BoardImpl::BoardImpl(int startLvl, int seed) : seed{seed}
{
    lvl = makeLevel(startLvl);

    currBlock = move(makeBlock(lvl->generateBlock()));
    nextBlock = lvl->generateBlock();
}

shared_ptr<Block> Board::BoardImpl::makeBlock(char c)
{
    shared_ptr<Block> newBlock;
    switch (c)
    {
        int level = lvl->getLvl();
    case 'I':
    {
        newBlock = make_shared<IBlock>(level);
        break;
    }
    case 'J':
    {
        newBlock = make_shared<JBlock>(level);
        break;
    }
    case 'L':
    {
        newBlock = make_shared<LBlock>(level);
        break;
    }
    case 'O':
    {
        newBlock = make_shared<OBlock>(level);
        break;
    }
    case 'S':
    {
        newBlock = make_shared<SBlock>(level);
        break;
    }
    case 'Z':
    {
        newBlock = make_shared<ZBlock>(level);
        break;
    }
    case 'T':
    {
        newBlock = make_shared<TBlock>(level);
        break;
    }
    default:
        // handle c isn't a block
        break;
    }
    return newBlock;
}

void Board::BoardImpl::setBlock(shared_ptr<Block> &block)
{
    currBlock = block;
}

void Board::BoardImpl::setLevel(int level)
{
    lvl = makeLevel(level);
}

Board::Board(int startLvl, int seed) : AbstractBoard{nullptr}, impl{make_unique<BoardImpl>(startLvl, seed)} {}

Board::~Board() = default;

shared_ptr<Block> Board::makeBlock(char c) { impl->makeBlock(c); }

void Board::setBlock(shared_ptr<Block> &block) { impl->setBlock(block); }

void Board::setLevel(int level) { impl->setLevel(level); }

vector<char> Board::getState() { return impl->state->getState(); }

char Board::getNext() { return impl->nextBlock; }

void Board::counterClockwise()
{
    impl->state->counterClockwise(impl->currBlock);
}

void Board::clockwise()
{
    impl->state->clockwise(impl->currBlock);
}

void Board::left()
{
    impl->state->left(impl->currBlock);
}

void Board::right()
{
    impl->state->right(impl->currBlock);
}

void Board::down()
{
    impl->state->down(impl->currBlock);
}
