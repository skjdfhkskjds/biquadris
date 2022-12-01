#include "../block.h"
#include "tblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;

int up = -1;
int down = 1;
int left = -1;
int right = 1;
int stay = 0;
// maps clockwise states
map<int, vector<vector<int>>> TBlock::rotationStates ={
    {0, {{left,up}, {right, up}, {0, 0}, {left, down}}},
    {1, {{right, up}, {right, down}, {0, 0}, {left, up}}},
    {2, {{right, down}, {left, down}, {0, 0}, {right, up}}}, 
    {3, {{left, down}, {left, up}, {0, 0}, {right, down}}}
};

TBlock::TBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(1,3);
    Coordinates b(0,2);
    Coordinates c(1,2);
    Coordinates d(2,2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('T');
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