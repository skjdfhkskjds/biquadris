#ifndef _LEVEL_
#define _LEVEL_

#include <memory>

class Level
{
    int seed, lvl;
public:
    Level(int seed);

    virtual char generateBlock() = 0;
};

#endif
