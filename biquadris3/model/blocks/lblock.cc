#include <vector>
#include "block.h"
#include "lblock.h"
#include "../../misc/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;

// maps clockwise states
map<int, vector<vector<int>>> LBlock::rotationStates = {
    {0, {{0, up * 2}, {left, up}, {left * 2, 0}, {left, down}}},
    {1, {{right * 2, down}, {right, 0}, {0, up}, {left, 0}}},
    {2, {{left, down}, {0, 0}, {right, up}, {0, up * 2}}},
    {3, {{left, 0}, {0, down}, {right, down * 2}, {right * 2, down}}}};

LBlock::LBlock(int lvl) : Block{'L', lvl}
{
    vector<Coordinates> coords;
    Coordinates a(0, 3);
    Coordinates b(1, 3);
    Coordinates c(2, 3);
    Coordinates d(2, 2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

void LBlock::clockwise()
{
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}
