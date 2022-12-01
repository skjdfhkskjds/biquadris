#include "../block.h"
#include "tblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;

// maps clockwise states
map<int, vector<vector<int>>> TBlock::rotationStates = {{0, {{0, -2}, {-1, -1}, {0, 0}, {-1, 1}}}, {1, {{2, 0}, {1, -1}, {0, 0}, {-1, -1}}}, {2, {{0, 2}, {1, 1}, {0, 0}, {1, -1}}}, {3, {{-2, 0}, {-1, 1}, {0, 0}, {1, 1}}}};

TBlock::TBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,3);
    Coordinates b(1,3);
    Coordinates c(1,2);
    Coordinates d(2,2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('s');
    setCoords(coords);
}
void TBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = getState() % 4;
    updateCoords(rotationStates[r]);
    setState(getState() + 1);
}

void TBlock::rotateCounterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    updateCoords(rotationStates[r]);
    setState(getState() - 1);
}