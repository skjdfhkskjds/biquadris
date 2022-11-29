#ifndef _LEVEL2_
#define _LEVEL2_

#include "../block.h"
#include "../leveldecorator.h"

class LevelTwo : public LevelDecorator
{
public:
    Block blockGenerator() override;
};

#endif
