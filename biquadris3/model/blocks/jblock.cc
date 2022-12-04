#include <vector>
#include "block.h"
#include "jblock.h"
#include "../../misc/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;

// maps clockwise states
map<int, vector<vector<int>>> JBlock::rotationStates = {
    {0, {{right, up}, {0, up * 2}, {left, up}, {left * 2, 0}}},
    {1, {{right, down}, {right * 2, down}, {right, 0}, {0, up}}},
    {2, {{left * 2, 0}, {left, down}, {0, 0}, {right, up}}},
    {3, {{0, up}, {left, 0}, {0, down}, {right, down * 2}}}};

map<int, vector<vector<int>>> JBlock::spawnStates = {
    {0, {{0,2},{0,3},{1,3},{2,3}}},
    {1, {{1,1},{0,1},{0,2},{0,3}}},
    {2, {{2,3},{2,2},{1,2},{0,2}}},
    {3, {{1,3},{1,2},{1,1},{0,1}}}
}

JBlock::JBlock(int lvl) : Block{'J', lvl}
{
    vector<Coordinates> coords;
    Coordinates a(0, 2);
    Coordinates b(0, 3);
    Coordinates c(1, 3);
    Coordinates d(2, 3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

void JBlock::clockwise()
{
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}
