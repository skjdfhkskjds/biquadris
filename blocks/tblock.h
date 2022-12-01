#ifndef _TBLOCK_
#define _TBLOCK_

#include "../block.h"

class TBlock : public Block
{
public:
    TBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
