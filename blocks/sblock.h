#ifndef _SBLOCK_
#define _SBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "../block.h"

class SBlock final : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    SBlock() noexcept;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
};

#endif
