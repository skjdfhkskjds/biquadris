#ifndef _BLOCK_
#define _BLOCK_

#include <memory>
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
    void update(std::vector<std::vector<int>>& coordChanges);

    virtual void rotateCounterClockwise() = 0;
    virtual void rotateClockwise() = 0;
    
    void shiftRight();
    void shiftLeft();
    void shiftDown();
    void decay();

public:
    Block() noexcept;
    ~Block() noexcept;
};

#endif
