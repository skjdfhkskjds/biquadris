#ifndef _OBLOCK_
#define _OBLOCK_

#include "../block.h"

class OBlock : public Block
{
public:
    OBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
