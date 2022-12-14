#ifndef _BLOCK_
#define _BLOCK_

#include <memory>
#include <vector>
#include "coordinates.h"

class Block
{
    class BlockImpl;
    std::unique_ptr<BlockImpl> impl;

protected:
    int getState();
    void setCoords(std::vector<Coordinates>& coords);
    void setState(int newState);
    void setChar(char newChar);

    bool isSafe();
    

public:
    void update(std::vector<std::vector<int>>& coordChanges);
    void shiftRight();
    void shiftLeft();
    void shiftDown();
    void decay();

    virtual void counterClockwise() = 0;
    virtual void clockwise() = 0;

    Block() noexcept;
    ~Block() noexcept;
    char getChar();
    std::vector<std::vector<int>> getCoords();
};

#endif
