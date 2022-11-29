#ifndef _ZBLOCK_
#define _ZBLOCK_

#include "../block.h"

class ZBlock : public Block
{
public:
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
