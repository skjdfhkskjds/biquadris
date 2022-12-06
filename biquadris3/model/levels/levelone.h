#ifndef _LEVELONE_
#define _LEVELONE_

#include <vector>
#include "level.h"
#include "../../common/random.h"

class LevelOne : public Level
{
    int i;
    Random randNum;
    std::vector<char> sequence;

public:
    LevelOne(int seed, std::vector<char> sequence);
    void setRandom(bool newValue) override;
    char generateBlock() override;
};

#endif
