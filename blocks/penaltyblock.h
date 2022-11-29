#ifndef _PENALTYBLOCK_
#define _PENALTYBLOCK_

#include "../block.h"

class PenaltyBlock : public Block
{
public:
    PenaltyBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
