#ifndef _LEVELTWO_
#define _LEVELTWO_

#include <vector>
#include "level.h"
#include "../../common/random.h"

class LevelTwo : public Level
{
    Random randNum;

public:
    LevelTwo(int seed);
    void setRandom(bool newValue) override;
    char generateBlock() override;
};

#endif
