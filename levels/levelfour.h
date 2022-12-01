#ifndef _LEVEL4_
#define _LEVEL04

#include "../block.h"
#include "../leveldecorator.h"

class LevelFour : public LevelDecorator
{
    std::unique_ptr<Block> penalty();

public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
