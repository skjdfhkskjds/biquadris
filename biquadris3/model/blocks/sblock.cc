#include <vector>
#include "block.h"
#include "sblock.h"
#include "../../common/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;
// SHORTEN THIS TO TWO STATES LATER

map<int, vector<vector<int>>> SBlock::rotationStates = {
    {0, {{0, up * 2}, {left, up}, {0, 0}, {left, down}}},
    {1, {{0, down * 2}, {right, down}, {0, 0}, {right, up}}},
    {2, {{0, up * 2}, {left, up}, {0, 0}, {left, down}}},
    {3, {{0, down * 2}, {right, down}, {0, 0}, {right, up}}}};

SBlock::SBlock(int lvl) : Block{'S', lvl}
{
    vector<Coordinates> coords;
    Coordinates a(0, 3);
    Coordinates b(1, 3);
    Coordinates c(1, 2);
    Coordinates d(2, 2);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

void SBlock::clockwise()
{
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}
