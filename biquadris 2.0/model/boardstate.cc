#include <memory>
#include <vector>
#include "boardstate.h"
#include "coordinates.h"
#include "board.h"
using namespace std;

#define width 11
#define height 18

BoardState::BoardState(unique_ptr<Block> currBlock, unique_ptr<Block> nextBlock) : currBlock{move(currBlock)}, nextBlock{move(nextBlock)}
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
    vector<vector<int>> temp = currBlock->getCoords();
  
    int len = temp.size();
    for (int i = 0; i < len; i++)
    {
        Coordinates coords(temp[i][0], temp[i][1]);
        coords.update(transform[i][0], transform[i][1]);
        int currIndex = coords.index();
        int currX = coords.getX();
        int currY = coords.getY();

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
    }
    return true;
}

void BoardState::addBlock(vector<vector<int>> transform)
{
    //latestBlock->update(transform);
}

std::vector<char> BoardState::getState()
{
    return boardState;
}

char BoardState::getNext()
{
    return nextBlock->getChar();
}

void BoardState::setBlock(unique_ptr<Block> block)
{
    currBlock = move(block);
}

void BoardState::counterClockwise()
{
    currBlock->counterClockwise();
}

void BoardState::clockwise()
{
    currBlock->clockwise();
}

void BoardState::left()
{
    currBlock->left();
}

void BoardState::right()
{
    currBlock->right();
}

void BoardState::down()
{
    currBlock->down();
}
