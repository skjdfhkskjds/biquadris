#ifndef _IBLOCK_
#define _IBLOCK_

#include "../block.h"

class IBlock : public Block
{
public:
    IBlock() noexcept;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
