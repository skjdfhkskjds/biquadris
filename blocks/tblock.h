#ifndef _TBLOCK_
#define _TBLOCK_

#include "../block.h"

class TBlock : public Block
{
    int rotationState;

public:
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
