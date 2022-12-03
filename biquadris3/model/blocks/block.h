#ifndef _BLOCK_
#define _BLOCK_

#include <vector>
#include <memory>
#include "../../misc/coordinates.h"

class Block
{
    class BlockImpl;
    std::unique_ptr<BlockImpl> impl;

protected:
    int getState(); // returns the rotation state

    // setter methods
    void setCoords(std::vector<Coordinates> &coords); // sets the coordinates of block
    void setState(int newState);                      // sets the rotation state

    void update(vector<vector<int>> transform); // updates coordinates by transform units

public:
    Block(char c, int lvl) noexcept;
    ~Block() noexcept;

    // getter methods
    char getChar();                         // returns the block's char
    std::vector<Coordinates &> getCoords(); // returns the block's coordinates
    int getLvl();                           // returns the level that the block was made

    // block transformations
    void right();            // shifts the block right
    void left();             // shifts the block left
    void down();             // shifts the block down
    void counterClockwise(); // rotates the block counters clockwise

    virtual void clockwise() = 0; // rotates the block clockwise

    void decay(); // decays the block
};

#endif
