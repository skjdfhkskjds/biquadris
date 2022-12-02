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
    {0, {{left,up}, {right, up}, {0, 0}, {left, down}}},
    {1, {{right, 0}, {right, down*2}, {0, down}, {left, 0}}},
    {2, {{0, 0}, {left*2, 0}, {left, up}, {0, up*2}}}, 
    {3, {{0, down}, {0, up}, {right, 0}, {right*2, down}}}
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
void TBlock::clockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}

void TBlock::counterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    update(rotationStates[r]);
    setState(getState() - 1);
}