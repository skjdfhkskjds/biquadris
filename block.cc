#include <vector>
#include "block.h"
#include "coordinates.h"

using namespace std;

struct BlockImpl
{
    vector<Coordinates> coords;
    int blockType, age, ageLimit;

    BlockImpl() : age{0}, ageLimit{-1} {};
};
