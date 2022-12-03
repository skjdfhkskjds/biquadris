#include "boardstate.h"

#define width 11
#define height 18

#define squared(x) x *x

BoardState::BoardState()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            state.emplace_back(' ');
        }
    }
}

Coordinates &BoardState::clearPiece(Coordinates &target)
{
    target.update(((-1 * target.getX()) - 1), ((-1 * target.getX()) - 1));
    state[target.index()] = ' ';
    return target;
}

bool BoardState::checkRow(int row)
{
    for (int x = 0; x < width; x++)
    {
        if (state[(row * width) + x] == ' ')
            return false;
    }
    return true;
}

void BoardState::clearRow(int row)
{
    if (!checkRow(row))
        return;
    // removes the pieces from the target row
    for (int x = 0; x < width; x++)
    {
        Coordinates toRemove{x, row};
        clearPiece(toRemove);
    }
    // shifts the rest of the board above it down one row
    for (int y = 3; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int i = ((width * y) + x);
            state[i + width] = state[i];
        }
    }
}

int BoardState::getScore(int row)
{
    int total = 0;
    // for every block in list
    for (auto &&block : placed)
    {
        auto coords = block->getCoords();
        bool clear = true;
        for (auto coord : coords)
        {
            // checks if every coordinate has been removed
            if (!coord.removed())
            {
                clear = false;
                break;
            }
        }
        // if the block is clear
        if (clear)
        {
            total += squared((block->getLvl() + 1));
            // pop from the vector
        }
    }
}
