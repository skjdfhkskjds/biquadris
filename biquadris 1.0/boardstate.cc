#include <vector>
#include <memory>
#include "boardstate.h"
#include "coordinates.h"

using namespace std;

BoardState::BoardState()
{
    for (int i = 0; i < width * height; i++)
    {
        boardState.emplace_back(' ');
    }
}

// returns true if row is filled and false otherwise
bool BoardState::checkRow(Coordinates &row)
{
    for (auto it = row.beginLine(); it == row.endLine(); ++it)
    {
        if (boardState[*it] == ' ')
            return false;
    }
    return true;
}

// clears a single row and handles board transformation
void BoardState::clearRow(int row)
{
    Coordinates dest{0, row};
    // checks if row is clear
    if (checkRow(dest))
    {
        // if clear, empties the row
        for (auto it = dest.beginLine(); it == dest.endLine(); ++it)
        {
            boardState[*it] = ' ';
        }
        // shifts the rest of the board down
        int i = dest.getPosition() - 1;
        for (; i >= 0; i--)
        {
            boardState[i + width] = boardState[i];
        }
    }
}

bool BoardState::isSafe(unique_ptr<Coordinates> dest)
{
    // if dest location is not currently free, collision occurs
    if (boardState[dest->getPosition()] != ' ') return false;
    return true;
}
