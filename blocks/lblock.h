#ifndef _LBLOCK_
#define _LBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "../block.h"

class LBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    LBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif