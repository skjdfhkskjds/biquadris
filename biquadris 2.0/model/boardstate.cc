#include <memory>
#include <vector>
#include "boardstate.h"
#include "coordinates.h"
#include "board.h"
using namespace std;

#define width 11
#define height 18

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
        if (boardState[toCheck.index()] == ' ')
            return false;
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

bool BoardState::isSafe(vector<vector<int>> transform)
{
    vector<vector<int>> temp = latestBlock->getCoords();
    vector<Coordinates> coords;
    int len = temp.size();
    for (int i = 0; i < len; i++)
    {
        Coordinates v(temp[i][0], temp[i][1]);
        coords.emplace_back(v);
    }
    int i = 0;
    for (auto coord : coords)
    {
        coords[i].update(transform[i][0], transform[i][1]);
        int currIndex = coords[i].index();
        int currX = coords[i].getX();
        int currY = coords[i].getY();

        // collision check at index of board
        if (boardState[currIndex] != ' ')
        {
            return false;
        }

        // check if block is out of bounds
        if (currX < 0 || currX > width || currY < 0 || currY > height)
        {
            return false;
        }
        i++;
    }
    return true;
}

void BoardState::addBlock(vector<vector<int>> transform)
{
    latestBlock->update(transform);
}

std::vector<char> BoardState::getState()
{
    return boardState;
}

char BoardState::getNextBlockChar()
{
    return nextBlock->getBlockChar();
}
