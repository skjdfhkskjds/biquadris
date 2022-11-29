#ifndef _SBLOCK_
#define _SBLOCK_

#include "../block.h"

class SBlock : public Block
{
public:
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
