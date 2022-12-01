#ifndef _ZBLOCK_
#define _ZBLOCK_

#include "../block.h"

class ZBlock : public Block
{
public:
    ZBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
