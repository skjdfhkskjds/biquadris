#include <vector>
#include "block.h"
#include "tblock.h"
#include "../../common/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;

// maps clockwise states
map<int, vector<vector<int>>> TBlock::rotationStates = {
    {0, {{left, up}, {right, up}, {0, 0}, {left, down}}},
    {1, {{right, 0}, {right, down * 2}, {0, down}, {left, 0}}},
    {2, {{0, 0}, {left * 2, 0}, {left, up}, {0, up * 2}}},
    {3, {{0, down}, {0, up}, {right, 0}, {right * 2, down}}}};

TBlock::TBlock(int lvl) : Block{'T', lvl}
{
    vector<Coordinates> coords;
    Coordinates a(1, 3);
    Coordinates b(0, 2);
    Coordinates c(1, 2);
    Coordinates d(2, 2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

void TBlock::clockwise()
{
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}
