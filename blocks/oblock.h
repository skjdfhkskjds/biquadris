#ifndef _OBLOCK_
#define _OBLOCK_

#include "../block.h"

class OBlock : public Block
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
