#include "boardstate.h"
#include "../common/exceptions.h"

#define width 11
#define height 18

#define neg(x) (-1 * (x))
#define squared(x) (x)*(x)

using namespace std;

BoardState::BoardState(int lvl) : lvl{lvl}
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            state.emplace_back(Square{x, y});
        }
    }
}

// clears the block from square and sets that block's coordinate at square to (-1, -1)
void BoardState::clearSquare(Coordinates &c) 
{
    vector<Coordinates &> coords = state[c.index()].getBlock()->getCoords();
    for (Coordinates & coord : coords)
    {
        // sets the current coordinate of block to (-1, -1)
        if (coord == c) 
        {
            coord.update(neg(c.getX()) - 1, neg(c.getY()) - 1);
            break;
        }
    }
    state[c.index()].removeBlock();
}

void BoardState::swap(Square &target, Square &dest)
{
    shared_ptr<Block> temp = target.getBlock();
    Coordinates tempCoords = target.getCoords();

    target.setBlock(dest.getBlock());
    target.setCoords(dest.getCoords());
    dest.setBlock(temp);
    dest.setCoords(tempCoords);
}

bool BoardState::isSafe(shared_ptr<Block> &block, vector<vector<int>> transform)
{
    int len = transform.size();
    for (int i = 0; i < len; i++)
    {
        Coordinates temp = block->getCoords()[i];
        temp.update(transform[i][0], transform[i][1]);
        // if new spot is already filled
        if (state[temp.index()].getChar() != ' ') return false;

        // check if block is out of bounds
        if (temp.getX() < 0 || temp.getX() > width || temp.getY() < 0 || temp.getY() > height)
        {
            return false;
        }
    }
    return true;
}

vector<char> BoardState::getState()
{
    vector<char> out;
    for (Square square : state)
    {
        out.emplace_back(square.getChar());
    }
    return out;
}

bool BoardState::checkRow(int row)
{
    for (int x = 0; x < width; x++)
    {
        Coordinates square{x, row};
        if (state[square.index()].getChar() == ' ') return false;
    }
    return true;
}

int BoardState::rowScore(vector<shared_ptr<Block> &> cleared)
{
    // points for clearing a line
    int score = squared(lvl + 1);
    for (shared_ptr<Block> block : cleared)
    {
        // points for full clearing a block
        if (block->fullCleared())
        {
            score += squared(block->getLvl() + 1);
        }
    }
}

int BoardState::clearRow(int row)
{
    if (!checkRow(row)) return;
    vector<shared_ptr<Block> &> cleared;
    // clearing row
    for (int x = 0; x < width; x++)
    {
        Coordinates target{x, row};
        cleared.emplace_back(state[target.index()].getBlock());
        clearSquare(target);
    }
    rowScore(cleared);
    // shift rows above down
    for (int y = row; y >= 3; y--)
    {
        // for every element in row, swap with element in row above
        for (int x = 0; x < width; x++)
        {
            int i = (width * y) + x;
            swap(state[i], state[i - width]);
        }
    }
}

void BoardState::apply(shared_ptr<Block> &block, vector<vector<int>> transform)
{
    if(!isSafe(block, transform)) throw invalid_move{};
    int len = transform.size();
    for (int i = 0; i < len; i++)
    {
        Coordinates before = block->getCoords()[i];
        // updates coords
        block->getCoords()[i].update(transform[i][0], transform[i][1]);

        // swaps squares
        state[before.index()].removeBlock();
        swap(state[before.index()], state[block->getCoords()[i].index()]);
    }
    // handles level heaviness
    if (block->isHeavy()) block->down();
}

void BoardState::clockwise(shared_ptr<Block> &block)
{
    apply(block, block->clockwise());
}

void BoardState::counterClockwise(shared_ptr<Block> &block)
{
    apply(block, block->counterClockwise());
}

void BoardState::left(shared_ptr<Block> &block)
{
    apply(block, block->left());
}

void BoardState::right(shared_ptr<Block> &block)
{
    apply(block, block->right());
}

void BoardState::down(shared_ptr<Block> &block)
{   
    apply(block, block->down());
}
