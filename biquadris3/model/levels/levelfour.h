#ifndef _LEVELFOUR_
#define _LEVELFOUR_

#include <vector>
#include "level.h"
#include "../../common/random.h"

class LevelFour : public Level
{
    int i;
    Random randNum;

public:
    LevelFour(int seed, std::vector<char> sequence);

    char generateBlock() override;
};

#endif
