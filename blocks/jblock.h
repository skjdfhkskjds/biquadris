#ifndef _JBLOCK_
#define _JBLOCK_

#include <vector>
#include <map>
#include <memory>
#include "../block.h"

class JBlock : public Block
{
    static std::map<int, std::vector<std::vector<int>>> rotationStates;
public:
    JBlock();
    void rotateCounterClockwise() override;
    void rotateClockwise() override;
    void decay();
};

#endif