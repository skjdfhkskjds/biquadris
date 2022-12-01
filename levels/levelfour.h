#ifndef _LEVEL4_
#define _LEVEL04

#include "../block.h"
#include "../Level.h"

class LevelFour : public Level
{
    std::unique_ptr<Block> penalty();

public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
