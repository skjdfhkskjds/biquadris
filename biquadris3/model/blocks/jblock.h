#ifndef _JBLOCK_
#define _JBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "block.h"

class JBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
    static std::map<int, std::vector<std::vector<int>>> spawnStates;
public:
    JBlock(int lvl) noexcept;
    void clockwise() override;
    void decay();
};

#endif