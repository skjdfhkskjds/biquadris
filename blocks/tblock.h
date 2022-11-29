#ifndef _TBLOCK_
#define _TBLOCK_

#include "block.h"

class TBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif