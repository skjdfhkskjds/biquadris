#ifndef _SBLOCK_
#define _SBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "block.h"

class SBlock final : public Block
{
    static std::map<int, std::vector<std::vector<int>>> spawnStates;
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    SBlock(int lvl) noexcept;
    void clockwise() override;
};

#endif
