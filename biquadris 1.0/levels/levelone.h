#ifndef _LEVEL1_
#define _LEVEL1_

#include "../block.h"
#include "../Level.h"

class LevelOne : public Level
{
public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
