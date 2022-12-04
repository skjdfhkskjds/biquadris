#include <vector>
#include "block.h"
#include "iblock.h"
#include "../../misc/coordinates.h"

#define up -1
#define down 1
#define left -1
#define right 1

using namespace std;



// maps clockwise states
map<int, vector<vector<int>>> IBlock::rotationStates = {
    {0, {{0, 0}, {right, up}, {right * 2, up * 2}, {right * 3, up * 3}}},
    {1, {{0, 0}, {left, down}, {left * 2, down * 2}, {left * 3, down * 3}}},
    {2, {{0, 0}, {right, up}, {right * 2, up * 2}, {right * 3, up * 3}}},
    {3, {{0, 0}, {left, down}, {left * 2, down * 2}, {left * 3, down * 3}}}};

map<int, vector<vector<int>>> IBlock::spawnStates = {
    {0, {{0,3},{1,3},{2,3},{3,3}}},
    {1, {{0,3},{0,2},{0,1},{0,0}}},
    {2, {{0,3},{1,3},{2,3},{3,3}}},
    {3, {{0,3},{0,2},{0,1},{0,0}}}
};


//spawn states
/*map<int, vector<vector<int>>> IBlock::spawnStates = {
    {0, {{},{},{},{}}},
    {1, {{},{},{},{}}},
    {2, {{},{},{},{}}},
    {3, {{},{},{},{}}}
};*/

IBlock::IBlock(int lvl) : Block{'I', lvl}
{
    vector<Coordinates> coords;
    Coordinates a(0, 3);
    Coordinates b(1, 3);
    Coordinates c(2, 3);
    Coordinates d(3, 3);
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);
    setCoords(coords);
}

void IBlock::clockwise()
{
    int r = getState() % 4;
    update(rotationStates[r]);
    setState(getState() + 1);
}
