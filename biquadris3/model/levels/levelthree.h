#ifndef _LEVELTHREE_
#define _LEVELTHREE_

#include <vector>
#include "level.h"

class LevelThree : public Level
{
    std::vector<char> sequence;
    bool isRandom;
public:
    LevelThree(int seed, std::vector<char> sequence);

    void setRandom(bool newValue); // modifies isRandom

    char generateBlock() override;
};

#endif
