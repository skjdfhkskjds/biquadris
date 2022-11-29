#ifndef _OBLOCK_
#define _OBLOCK_

#include "block.h"

class OBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif