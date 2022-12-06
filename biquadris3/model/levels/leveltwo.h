#ifndef _LEVELTWO_
#define _LEVELTWO_

#include <vector>
#include "level.h"
#include "../../common/random.h"

class LevelTwo : public Level
{
    Random randNum;
    std::vector<char> sequence;

public:
    LevelTwo(int seed, std::vector<char> sequence);
    void setRandom(bool newValue) override;
    char generateBlock() override;
};

#endif
