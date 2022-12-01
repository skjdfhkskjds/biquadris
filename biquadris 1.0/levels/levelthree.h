#ifndef _LEVEL3_
#define _LEVEL3_

#include "../block.h"
#include "../Level.h"

class LevelThree : public Level
{
public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
