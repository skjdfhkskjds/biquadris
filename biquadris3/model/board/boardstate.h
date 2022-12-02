#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <vector>
#include <memory>
#include "../blocks/block.h"

class BoardState
{
    std::vector<char> state;
    std::vector<std::unique_ptr<Block>> placed;

public:
    BoardState();

    // boardstate manipulations
    bool checkRow(int row);
    void clearRow(int row);

    // transformation modifiers
    bool isSafe(std::vector<std::vector<int>> transform);                 // checks whether a transformation is safe
    void addBlock(Block &block, std::vector<std::vector<int>> transform); // adds a block to the boardState

    // getter methods
    std::vector<char> getState(); // returns the boardState
    char getNext();               // returns the typeof next Block

    // block transformation
    unique_ptr<Block> counterClockwise(unique_ptr<Block> block); // rotates the block counter clockwise
    unique_ptr<Block> clockwise(unique_ptr<Block> block);        // rotates the block clockwise
    unique_ptr<Block> right(unique_ptr<Block> block);            // shifts the block right
    unique_ptr<Block> left(unique_ptr<Block> block);             // shifts the block left
    unique_ptr<Block> down(unique_ptr<Block> block);             // shifts the block down
};

#endif
