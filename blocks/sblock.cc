#include "../block.h"
#include "sblock.h"
#include "coordinates.h"
#include <vector>
#include <memory>

using namespace std;

// maps clockwise states
map<int, vector<vector<int>>> SBlock::rotationStates = {{0, {{0, -2}, {-1, -1}, {0, 0}, {-1, 1}}}, {1, {{2, 0}, {1, -1}, {0, 0}, {-1, -1}}}, {2, {{0, 2}, {1, 1}, {0, 0}, {1, -1}}}, {3, {{-2, 0}, {-1, 1}, {0, 0}, {1, 1}}}};

SBlock::SBlock() : Block{} {}

void SBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = getState() % 4;
    updateCoords(rotationStates[r]);
    setState(getState() + 1);
}

void SBlock::rotateCounterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    updateCoords(rotationStates[r]);
    setState(getState() - 1);
}
