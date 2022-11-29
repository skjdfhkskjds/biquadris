#ifndef _LBLOCK_
#define _LBLOCK_

#include "block.h"

class LBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif