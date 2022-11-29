#ifndef _TBLOCK_
#define _TBLOCK_

#include "../block.h"

class TBlock : public Block
{
public:
    TBlock();
    void updateCoords(int x, int y) override;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
