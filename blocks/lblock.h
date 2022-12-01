#ifndef _LBLOCK_
#define _LBLOCK_

#include "../block.h"

class LBlock : public Block
{
public:
    LBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
