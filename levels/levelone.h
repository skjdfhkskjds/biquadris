#ifndef _LEVEL1_
#define _LEVEL1_

#include "../block.h"
#include "../blocks/iblock.h"
#include "../blocks/sblock.h"
#include "../blocks/jblock.h"
#include "../blocks/lblock.h"
#include "../blocks/oblock.h"
#include "../blocks/tblock.h"
#include "../blocks/zblock.h"
#include "../leveldecorator.h"

class LevelOne : public LevelDecorator
{

public:
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
