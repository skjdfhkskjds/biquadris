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
/*map<int, vector<vector<int>>> TBlock::rotationStates = {
    {0, {{left, up}, {right, up}, {0, 0}, {left, down}}},
    {1, {{right, 0}, {right, down * 2}, {0, down}, {left, 0}}},
    {2, {{0, 0}, {left * 2, 0}, {left, up}, {0, up * 2}}},
    {3, {{0, down}, {0, up}, {right, 0}, {right * 2, down}}}
}; */

map<int, vector<vector<int>>> TBlock::spawnStates = {
    {0, {{1,3},{0,2},{1,2},{2,2}}},
    {1, {{0,2},{1,1},{1,2},{1,3}}},
    {2, {{1,2},{0,3},{1,3},{2,3}}},
    {3, {{1,2},{0,1},{0,2},{0,3}}}
};

TBlock::TBlock(int lvl) noexcept : Block{'T', lvl}
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

vector<vector<int>> TBlock::clockwise()
{
    int r = getState() % 4;
    setState(getState() + 1);
    int dr = getState() % 4;
    vector<vector<int>> retVal = vviSubtraction(spawnStates[dr], spawnStates[r]);
    return retVal;
}

vector<vector<int>> TBlock::counterClockwise()
{
    int r = getState() % 4;
    setState(getState() + 3);
    int dr = getState() % 4;
    vector<vector<int>> retVal = vviSubtraction(spawnStates[dr], spawnStates[r]);
    return retVal;
}
