#ifndef _LEVEL1_
#define _LEVEL1_

#include "block.h"
#include "leveldecorator.h"

class LevelOne : public LevelDecorator
{
public:
    Block blockGenerator() override;
};

#endif
