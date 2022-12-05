#ifndef _LEVEL_
#define _LEVEL_

#include <vector>

class Level
{
    int seed;
    int lvlNum;
    std::vector<char> sequence;

public:
    Level(int seed, int lvlNum, std::vector<char> sequence);
    int getLevel();
    virtual ~Level() noexcept;
    virtual char blockGenerator() = 0;
};

#endif
