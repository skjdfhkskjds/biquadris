#ifndef _LEVELONE_
#define _LEVELONE_

#include <vector>
#include "level.h"

class LevelOne : public Level
{
    std::vector<char> sequence;
public:
    LevelOne(int seed, std::vector<char> sequence);

    char generateBlock() override;
};

#endif
