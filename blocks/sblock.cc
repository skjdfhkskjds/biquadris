#include "../block.h"
#include "sblock.h"
#include "coordinates.h"
#include <vector>
#include <memory>

using namespace std;

std::map<int, std::vector<std::vector<int>>> SBlock::rotationStates = {{0, {{0, -2}, {-1, -1}, {0, 0}, {-1, 1}}}, {1, {{2, 0}, {1, -1}, {0, 0}, {-1, -1}}}, {2, {{0, 2}, {1, 1}, {0, 0}, {1, -1}}}, {3, {{-2, 0}, {-1, 1}, {0, 0}, {1, 1}}}};

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
    // 0 -> 1, 1 -> 0, 2 -> 3, 3 -> 2
    int r = getState() % 4;
    switch (r)
    {
    case 0:
        updateCoords(rotationStates[1]);
        break;
    case 1:
        updateCoords(rotationStates[0]);
        break;
    case 2:
        updateCoords(rotationStates[2]);
        break;
    case 3:
        updateCoords(rotationStates[3]);
        break;
    }
    setState(getState() + 1);
}

