#include <memory>
#include <vector>
#include "boardstate.h"

BoardState::BoardState() : latestBlock{nullptr} 
{
    for (int i = 0; i < width * height; i++)
    {
        boardState.emplace_back(' ');
    }
}

bool BoardState::checkRow(int row)
{
    for (int x = 0; x < width; x++)
    {
        Coordinates toCheck{x, row};
        if (boardState[toCheck.index()] == ' ') return false;
    }
    return true;
}

void BoardState::clearRow(int row)
{
    if (checkRow(row))
    {
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
                boardState[i + width] = boardState[i];
            }
        }
    }
}

void BoardState::clearPiece(Coordinates &c)
{
    boardState[c.index()] = ' ';
}

std::vector<char> BoardState::getState() {
    return boardState;
}

char BoardState::getNextBlockChar() {
    return nextBlock->getBlockChar();
}