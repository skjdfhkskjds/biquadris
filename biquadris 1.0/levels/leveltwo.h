#ifndef _LEVEL2_
#define _LEVEL2_

#include "../block.h"
#include "../Level.h"

class LevelTwo : public Level
{
public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
