#ifndef _ZBLOCK_
#define _ZBLOCK_

#include "block.h"

class ZBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif