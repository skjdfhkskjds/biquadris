#include "../block.h"
#include "zblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;

int up = -1;
int down = 1;
int left = -1;
int right = 1;
// maps clockwise states
//CAN BE CONFIGURED FOR 2 ROTATION STATES
map<int, vector<vector<int>>> ZBlock::rotationStates ={
    {0, {{right,up}, {0,0}, {left, up}, {2 * left, 0}}},
    {1, {{left, down}, {0,0}, {right, down}, {2*right, 0}}},
    {2, {{right,up}, {0,0}, {left, up}, {2 * left, 0}}},
    {3, {{left, down}, {0,0}, {right, down}, {2*right, 0}}}
};

ZBlock::ZBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,2);
    Coordinates b(1,2);
    Coordinates c(1,3);
    Coordinates d(2,3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('Z');
    setCoords(coords);
}
void ZBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = getState() % 4;
    updateCoords(rotationStates[r]);
    setState(getState() + 1);
}

void ZBlock::rotateCounterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    updateCoords(rotationStates[r]);
    setState(getState() - 1);
}