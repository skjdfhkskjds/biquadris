#ifndef _LEVEL_
#define _LEVEL_

#include "block.h"

class Level
{
public:
    Level(int startLvl);
    virtual ~Level();
    virtual std::unique_ptr<Block> blockGenerator() = 0;
};

#endif
