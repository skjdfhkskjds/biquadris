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
    void update(std::vector<std::vector<int>>& coordChanges);

    virtual void rotateCounterClockwise() = 0;
    virtual void rotateClockwise() = 0;
    
public:
    void shiftRight();
    void shiftLeft();
    void shiftDown();
    void decay();

    Block() noexcept;
    ~Block() noexcept;
    char getBlockChar();
    std::vector<std::vector<int>> getCoords();
};

#endif
