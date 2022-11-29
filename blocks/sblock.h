#ifndef _SBLOCK_
#define _SBLOCK_

#include "../block.h"

class SBlock : public Block
{
public:
    SBlock();
    void updateCoords(int x, int y) override;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
