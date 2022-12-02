#include "../block.h"
#include "sblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;
//SHORTEN THIS TO TWO STATES LATER
// maps clockwise states
int up = -1;
int down = 1;
int left = -1;
int right = 1;

map<int, vector<vector<int>>> SBlock::rotationStates = {
    {0, {{0, up*2}, {left, up}, {0, 0}, {left, down}}},
    {1, {{0, down*2}, {right, down}, {0, 0}, {right, up}}},
    {2, {{0, up*2}, {left, up}, {0, 0}, {left, down}}},
    {3, {{0, down*2}, {right, down}, {0, 0}, {right, up}}}
};

SBlock::SBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,3);
    Coordinates b(1,3);
    Coordinates c(1,2);
    Coordinates d(2,2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('S');
    setCoords(coords);
}

void SBlock::clockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}

void SBlock::counterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    update(rotationStates[r]);
    setState(getState() - 1);
}
