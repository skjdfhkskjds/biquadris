#ifndef _PENALTYBLOCK_
#define _PENALTYBLOCK_

#include "../block.h"

class PenaltyBlock : public Block
{
public:
    PenaltyBlock();
    void counterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
