#include "boardstate.h"

#define width 11
#define height 18

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

bool BoardState::checkRow(int row)
{
    for (int x = 0; x < width; x++)
    {
        if (state[(row * width) + x] == ' ') return false;
    }
    return true;
}

void BoardState::clearRow(int row)
{
    if (!checkRow(row)) return;
    for ()
}
