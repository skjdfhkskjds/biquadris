#include "boardstate.h"
#include "coordinates.h"

BoardState::BoardState()
{
    for (int i = 0; i < width * height; i++)
    {
        boardState.emplace_back(' ');
    }
}

bool BoardState::checkRow(int row)
{
    Coordinates rowBeginning{0, row, width};
    if ()
    {

    }
}

void BoardState::clearRow(int row)
{

}
