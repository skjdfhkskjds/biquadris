#ifndef _LEVELFOUR_
#define _LEVELFOUR_

#include <vector>
#include "level.h"
#include "../../common/random.h"

class LevelFour : public Level
{
    std::vector<char> sequence;
    bool isRandom;
    int i;
    Random randNum;

public:
    LevelFour(int seed, std::vector<char> sequence);

    void setRandom(bool newValue) override; // modifies isRandom

    char generateBlock() override;
};

#endif
