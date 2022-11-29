#ifndef _SBLOCK_
#define _SBLOCK_

#include "block.h"

class SBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif