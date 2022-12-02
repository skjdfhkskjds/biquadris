#include "../block.h"
#include "jblock.h"
#include "../coordinates.h"
#include <vector>
#include <memory>

using namespace std;

int up = -1;
int down = 1;
int left = -1;
int right = 1;
// maps clockwise states
map<int, vector<vector<int>>> JBlock::rotationStates ={
    {0, {{right, up}, {0, up*2}, {left, up}, {left*2, 0}}},
    {1, {{right, down}, {right*2, down}, {right, 0}, {0, up}}},
    {2, {{left*2, 0}, {left, down}, {0, 0}, {right, up}}}, 
    {3, {{0, up}, {left, 0}, {0, down}, {right, down*2}}}
};

JBlock::JBlock() : Block{} {
    vector<Coordinates> coords;
    Coordinates a(0,2);
    Coordinates b(0,3);
    Coordinates c(1,3);
    Coordinates d(2,3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d); 
    setChar('L');
    setCoords(coords);
}
void JBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}

void JBlock::rotateCounterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    // 3 -> 2, 2 -> 1, 1 -> 0, 0 -> 3
    int r = (getState() + 3) % 4;
    update(rotationStates[r]);
    setState(getState() - 1);
}