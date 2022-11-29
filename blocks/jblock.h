#ifndef _JBLOCK_
#define _JBLOCK_

#include "../block.h"

class JBlock : public Block
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
