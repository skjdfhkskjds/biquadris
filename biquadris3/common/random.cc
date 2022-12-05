#include "random.h"

Random::Random(int seed=1)
{
    srand(seed);
}

int getRand() { return rand(); }
