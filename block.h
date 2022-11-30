#ifndef _BLOCK_
#define _BLOCK_

#include <memory>

class Block
{
protected:
    class BlockImpl;
    std::unique_ptr<BlockImpl> pImpl;
public:
    const enum {I=0, J, L, O, S, Z, T, Single};

    Block() noexcept;
    ~Block() noexcept;

    int getState();
    void setState(int newState);

    bool isSafe();
    void updateCoords(std::vector<std::vector<int>>& coordChanges);

    virtual void rotateCounterClockwise() = 0;
    virtual void rotateClockwise() = 0;
    
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif
