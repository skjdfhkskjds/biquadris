#ifndef _IBLOCK_
#define _IBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "../block.h"

class IBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    IBlock() noexcept;
    void counterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif