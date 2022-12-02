#ifndef _OBLOCK_
#define _OBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "../block.h"

class OBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    OBlock() noexcept;
    void counterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif
