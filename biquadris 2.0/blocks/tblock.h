#ifndef _TBLOCK_
#define _TBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "../block.h"

class TBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    TBlock() noexcept;
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif