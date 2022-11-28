#ifndef _BLOCK_
#define _BLOCK_

#include <memory>

class Block
{
    class BlockImpl;
    std::unique_ptr<BlockImpl> pImpl;
public:
    const enum {I=0, J, L, O, S, Z, T, Single};

    Block() noexcept;
    ~Block() noexcept;

    virtual void updateCoords(int x, int y) = 0;
    virtual void rotateCounterClockwise() = 0;
    virtual void rotateClockwise() = 0;
    virtual void shiftRight() = 0;
    virtual void shiftLeft() = 0;
    void decay();
};

#endif
