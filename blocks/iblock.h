#ifndef _IBLOCK_
#define _IBLOCK_

#include "../block.h"

class IBlock : public Block
{
public:
    IBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void shiftRight() override;
    void shiftLeft() override;
    void decay();
};

#endif
