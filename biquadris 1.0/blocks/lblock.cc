#include "../block.h"
#include "lblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;

int up = -1;
int down = 1;
int left = -1;
int right = 1;
// maps clockwise states
map<int, vector<vector<int>>> LBlock::rotationStates ={
    {0, {{0, up*2}, {left, up}, {left*2, 0}, {left, down}}},
    {1, {{right*2, down}, {right, 0}, {0, up}, {left, 0}}},
    {2, {{left, down}, {0, 0}, {right, up}, {0, up*2}}}, 
    {3, {{left, 0}, {0, down}, {right, down*2}, {right*2, down}}}
};

LBlock::LBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,3);
    Coordinates b(1,3);
    Coordinates c(2,3);
    Coordinates d(2,2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('L');
    setCoords(coords);
}
void LBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = getState() % 4;
    updateCoords(rotationStates[r]);
    setState(getState() + 1);
}

void LBlock::counterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    updateCoords(rotationStates[r]);
    setState(getState() - 1);
}