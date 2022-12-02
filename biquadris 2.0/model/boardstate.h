#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <vector>
#include "block.h"
#include "coordinates.h"

class BoardState final
{
    std::vector<char> boardState;
    std::unique_ptr<Block> latestBlock;

public:
    BoardState() noexcept;

    bool checkRow(int row);          // checks whether the row is entirely filled
    void clearRow(int row);          // clears the row and shifts all elements above it down
    void clearPiece(Coordinates &c); // clears the piece at c

    bool isSafe(std::vector<std::vector<int>> transform); // checks whether a transformation is safe
    void addBlock(Block& block);                           // adds a block to the boardState

    std::vector<char> getState(); // returns the boardState
};

#endif
