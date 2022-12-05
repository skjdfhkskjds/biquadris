#include <vector>
#include "block.h"
#include "zblock.h"
#include "../../common/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;

// maps clockwise states
// CAN BE CONFIGURED FOR 2 ROTATION STATES
map<int, vector<vector<int>>> ZBlock::rotationStates = {
    {0, {{right, up}, {0, 0}, {left, up}, {2 * left, 0}}},
    {1, {{left, down}, {0, 0}, {right, down}, {2 * right, 0}}},
    {2, {{right, up}, {0, 0}, {left, up}, {2 * left, 0}}},
    {3, {{left, down}, {0, 0}, {right, down}, {2 * right, 0}}}};

map<int, vector<vector<int>>> ZBlock::spawnStates = {
    {0, {{0,2},{1,2},{1,3},{2,3}}},
    {1, {{1,1},{1,2},{0,2},{0,3}}},
    {2, {{0,2},{1,2},{1,3},{2,3}}},
    {3, {{1,1},{1,2},{0,2},{0,3}}},
};

ZBlock::ZBlock(int lvl) : Block{'Z', lvl}
{
    vector<Coordinates> coords;
    Coordinates a(0, 2);
    Coordinates b(1, 2);
    Coordinates c(1, 3);
    Coordinates d(2, 3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

void ZBlock::clockwise()
{
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}
