#ifndef _LEVELZERO_
#define _LEVELZERO_

#include <vector>
#include "level.h"

class LevelZero : public Level
{
    int i;
    std::vector<char> sequence;
public:
    LevelZero(int seed, std::vector<char> sequence);
    void setRandom(bool newValue) override;
    char generateBlock() override;
};

#endif
