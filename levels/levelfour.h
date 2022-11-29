#ifndef _LEVEL4_
#define _LEVEL04

#include "../block.h"
#include "../leveldecorator.h"

class LevelFour : public LevelDecorator 
{
    Block penalty();
public:
    Block blockGenerator() override;
};

#endif
