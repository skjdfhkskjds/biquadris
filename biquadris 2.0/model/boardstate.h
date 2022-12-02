#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <vector>
#include <memory>
#include "block.h"
#include "coordinates.h"

class BoardState final
{
    std::vector<char> boardState;
    std::unique_ptr<Block> currBlock;
    std::unique_ptr<Block> nextBlock;

public:
    BoardState(std::unique_ptr<Block> currBlock, std::unique_ptr<Block> nextBlock) noexcept;

    bool checkRow(int row);          // checks whether the row is entirely filled
    void clearRow(int row);          // clears the row and shifts all elements above it down
    void clearPiece(Coordinates &c); // clears the piece at c

    bool isSafe(std::vector<std::vector<int>> transform);   // checks whether a transformation is safe
    void addBlock(std::vector<std::vector<int>> transform); // adds a block to the boardState

    std::vector<char> getState(); // returns the boardState
    char getNext();               // returns the typeof next Block

    void setBlock(std::unique_ptr<Block> block); // sets value of currBlock to block
    void counterClockwise();                     // rotates the block counter clockwise
    void clockwise();                            // rotates the block clockwise
    void right();                                // shifts the block right
    void left();                                 // shifts the block left
    void down();                                 // shifts the block down
};

#endif
