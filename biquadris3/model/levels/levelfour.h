#ifndef _LEVELFOUR_
#define _LEVELFOUR_

#include <vector>
#include "level.h"

class LevelFour : public Level
{
    std::vector<char> sequence;
    bool isRandom;
public:
    LevelFour(int seed, std::vector<char> sequence);

    void setRandom(bool newValue); // modifies isRandom

    char generateBlock() override;
};

#endif
