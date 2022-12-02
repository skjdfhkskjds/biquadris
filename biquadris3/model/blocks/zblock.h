#ifndef _ZBLOCK_
#define _ZBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "block.h"

class ZBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    ZBlock(int lvl) noexcept;
    void clockwise() override;
};

#endif
