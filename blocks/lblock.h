#ifndef _LBLOCK_
#define _LBLOCK_

#include "../block.h"

class LBlock : public Block
{
public:
    LBlock();
    void updateCoords(int x, int y) override;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
