#ifndef _PENALTYBLOCK_
#define _PENALTYBLOCK_

#include "block.h"

class PenaltyBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif