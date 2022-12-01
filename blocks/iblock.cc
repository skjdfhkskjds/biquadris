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
// maps clockwise states
map<int, vector<vector<int>>> TBlock::rotationStates ={
    {0, {{0,0}, {right, up}, {right*2, up*2}, {right*3, up*3}}},
    {1, {{0, 0}, {left, down}, {left*2, down*2}, {left*3, down*3}}},
    {2, {{0,0}, {right, up}, {right*2, up*2}, {right*3, up*3}}},
    {3, {{0, 0}, {left, down}, {left*2, down*2}, {left*3, down*3}}}
};

TBlock::TBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,3);
    Coordinates b(1,3);
    Coordinates c(2,3);
    Coordinates d(3,3);
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