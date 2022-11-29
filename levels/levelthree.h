#ifndef _LEVEL3_
#define _LEVEL3_

#include "../block.h"
#include "../leveldecorator.h"

class LevelThree : public LevelDecorator
{
public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
