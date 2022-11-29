#ifndef _LEVEL0_
#define _LEVEL0_

#include "block.h"
#include "leveldecorator.h"

class LevelZero : public LevelDecorator
{
public:
    Block blockGenerator() override;
};

#endif
