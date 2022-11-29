#ifndef _IBLOCK_
#define _IBLOCK_

#include "block.h"

class IBlock
{
public:
    void rotateCounterClockwise();
    void rotateClockwise();
    void shiftRight();
    void shiftLeft();
    void decay();
};

#endif
