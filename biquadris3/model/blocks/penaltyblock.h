#ifndef _PENALTYBLOCK_
#define _PENALTYBLOCK_

#include "block.h"

class PenaltyBlock : public Block
{
    
public:
    PenaltyBlock();
    void clockwise() override;
};

#endif
