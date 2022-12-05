#ifndef _BLOCK_
#define _BLOCK_

#include <vector>
#include <memory>
#include "../../common/coordinates.h"

class Block
{
    class BlockImpl;
    std::unique_ptr<BlockImpl> impl;

protected:
    int getState(); // returns the rotation state

    // setter methods
    void setCoords(std::vector<Coordinates> &coords); // sets the coordinates of block
    void setState(int newState);                      // sets the rotation state

    void decay(); // decays the block

public:
    Block(char c, int lvl) noexcept;

    // getter methods
    char getChar();                         // returns the block's char
    std::vector<Coordinates &> getCoords(); // returns the block's coordinates
    int getLvl();                           // returns the level that the block was made
    bool fullCleared();                     // returns whether a block has been fully cleared

    // block transformations
    std::vector<std::vector<int>> right(); // shifts the block right
    std::vector<std::vector<int>> left();  // shifts the block left
    std::vector<std::vector<int>> down();  // shifts the block down

    virtual std::vector<std::vector<int>> clockwise() = 0;        // rotates the block clockwise
    virtual std::vector<std::vector<int>> counterClockwise() = 0; // rotates the block counters clockwise
};

#endif
