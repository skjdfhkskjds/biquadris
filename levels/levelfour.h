#ifndef _LEVEL4_
#define _LEVEL04

#include "../block.h"
#include "../leveldecorator.h"

class LevelFour : public LevelDecorator 
{
    Block penalty();
public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
