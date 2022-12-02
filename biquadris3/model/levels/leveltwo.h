#ifndef _LEVELTWO_
#define _LEVELTWO_

#include <vector>
#include "level.h"

class LevelTwo : public Level
{
    std::vector<char> sequence;
public:
    LevelTwo(int seed, std::vector<char> sequence);

    char generateBlock() override;
};

#endif
