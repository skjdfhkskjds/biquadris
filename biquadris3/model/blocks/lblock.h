#ifndef _LBLOCK_
#define _LBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "block.h"

class LBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
    static std::map<int, std::vector<std::vector<int>>> spawnStates;
public:
    LBlock(int lvl) noexcept;
    void clockwise() override;
};

#endif