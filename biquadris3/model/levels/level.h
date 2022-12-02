#ifndef _LEVEL_
#define _LEVEL_

#include <memory>

class Level
{
    int seed, lvl;
public:
    Level(int seed, int lvl);

    // getter methods
    int getLvl(); // returns lvl

    virtual char generateBlock() = 0; // generates a block
};

#endif
