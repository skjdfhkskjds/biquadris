#ifndef _JBLOCK_
#define _JBLOCK_

#include "../block.h"

class JBlock : public Block
{
public:
    JBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
