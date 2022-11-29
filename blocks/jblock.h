#ifndef _JBLOCK_
#define _JBLOCK_

#include "../block.h"

class JBlock : public Block
{
public:
    JBlock();
    void updateCoords(int x, int y) override;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
