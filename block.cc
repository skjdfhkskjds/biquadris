#include <vector>
#include "block.h"
#include "coordinates.h"

using namespace std;

struct BlockImpl
{
    vector<unique_ptr<Coordinates>> coords;
    int blockType, age, ageLimit, rotationState;
    char c;

    BlockImpl() : age{0}, ageLimit{-1}, rotationState{0} {};
};
