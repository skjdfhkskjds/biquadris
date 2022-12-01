#include "../block.h"
#include "oblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;

int up = -1;
int down = 1;
int left = -1;
int right = 1;
// maps clockwise states
map<int, vector<vector<int>>> OBlock::rotationStates ={
    {0, {{0, up}, {0, up}, {0, up}, {0, up}}},
    {1, {{right, 0}, {right, 0}, {right, 0}, {right, 0}}},
    {2, {{0, down}, {0, down}, {0, down}, {0, down}}}, 
    {3, {{left, 0}, {left, 0}, {left, 0}, {left, 0}}}
};

OBlock::OBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,2);
    Coordinates b(1,2);
    Coordinates c(0,3);
    Coordinates d(1,3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('O');
    setCoords(coords);
}
void OBlock::rotateClockwise() //do nothing
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    /*
    int r = getState() % 4;
    updateCoords(rotationStates[r]);
    setState(getState() + 1);
    */
}

void OBlock::rotateCounterClockwise() //do nothing
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    /*
    int r = (getState() + 3) % 4;
    updateCoords(rotationStates[r]);
    setState(getState() - 1);
    */
}