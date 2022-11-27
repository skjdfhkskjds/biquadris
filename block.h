#ifndef _BLOCK_
#define _BLOCK_

#include <memory>

class Block
{
    class BlockImpl;
    std::unique_ptr<BlockImpl> pImpl;
public:
    Block() noexcept;
    ~Block() noexcept;

    virtual void updateCoords(int x, int y);
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif
