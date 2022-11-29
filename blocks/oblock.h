#ifndef _OBLOCK_
#define _OBLOCK_

#include "../block.h"

class OBlock : public Block
{
public:
    OBlock();
    void updateCoords(int x, int y) override;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
