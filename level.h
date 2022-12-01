#ifndef _LEVELS_
#define _LEVELS_

#include "block.h"

class Level
{
public:
    virtual ~Level() {}
    virtual std::unique_ptr<Block> blockGenerator() = 0;
};

#endif