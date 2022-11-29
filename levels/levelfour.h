#ifndef _LEVEL4_
#define _LEVEL04

#include "../block.h"
#include "../leveldecorator.h"

class LevelFour : public LevelDecorator 
{
    Block penaltyBlock();
public:
    Block blockGenerator() override;
};

#endif
