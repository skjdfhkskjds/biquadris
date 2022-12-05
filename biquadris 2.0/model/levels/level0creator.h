#ifndef _LEVEL0CREATOR_
#define _LEVEL0CREATOR_

#include <vector>
#include "../block.h"
#include "levelfactory.h"

class LevelZeroCreator : public LevelFactory
{
    std::vector<char> sequence;

public:
    std::unique_ptr<Level> createLevel() override;
};

#endif
