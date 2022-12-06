#include "random.h"

Random::Random(int seed)
{
    srand(seed);
}

int getRand(int mod) { return rand() % mod; }
