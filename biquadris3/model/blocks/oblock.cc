#include <vector>
#include "block.h"
#include "oblock.h"
#include "../../common/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;

// maps clockwise states
/*map<int, vector<vector<int>>> OBlock::rotationStates = {
    {0, {{0, up}, {0, up}, {0, up}, {0, up}}},
    {1, {{right, 0}, {right, 0}, {right, 0}, {right, 0}}},
    {2, {{0, down}, {0, down}, {0, down}, {0, down}}},
    {3, {{left, 0}, {left, 0}, {left, 0}, {left, 0}}}}; */

map<int, vector<vector<int>>> OBlock::spawnStates = {
    {0, {{0,2},{1,2},{0,3},{1,3}}},
    {1, {{0,2},{1,2},{0,3},{1,3}}},
    {2, {{0,2},{1,2},{0,3},{1,3}}},
    {3, {{0,2},{1,2},{0,3},{1,3}}}
};

OBlock::OBlock(int lvl) : Block{'O', lvl}
{
    vector<Coordinates &> coords;
    Coordinates a(0, 2);
    Coordinates b(1, 2);
    Coordinates c(0, 3);
    Coordinates d(1, 3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

vector<vector<int>> OBlock::clockwise() {
    vector<vector<int>> retVal = {{0,0}, {0,0}, {0,0}, {0,0}};
    return retVal;
}
