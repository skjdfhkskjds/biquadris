#ifndef _JBLOCK_
#define _JBLOCK_

#include "block.h"

class JBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif