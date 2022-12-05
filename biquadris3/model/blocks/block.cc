#include "block.h"
#include <map>
using namespace std;

struct Block::BlockImpl
{
    char c;
    int lvl, age, maxAge, rotationState;
    bool isHeavy; // heavinesss based on level
    std::vector<Coordinates> coords;

    BlockImpl(char c, int lvl) noexcept;
    ~BlockImpl() noexcept = default;

    Coordinates &getCoords();
};

Block::BlockImpl::BlockImpl(char c, int lvl) noexcept //: lvl{lvl}, age{0}, maxAge{-1}, rotationState{0}, c{c}, isHeavy{(lvl >= 3) ? true : false}
{
    lvl = lvl;
    age = 0;
    maxAge = -1;
    rotationState = 0;
    c = c;
    isHeavy = ((lvl >= 3) ? true : false);
}

Block::Block(char c, int lvl) noexcept : impl{make_unique<Block::BlockImpl>(c, lvl)} {}

Block::~Block() noexcept = default;

int Block::getState() { return impl->rotationState; }

char Block::getChar() { return impl->c; }

int Block::getLvl() { return impl->lvl; }

bool Block::fullCleared()
{
    for (Coordinates & coord : impl->coords)
    {
        if (coord.getX() != -1 || coord.getY() != -1) return false;
    }
    return true;
}

vector<Coordinates> Block::getCoords() { return impl->coords; }

void Block::setCoords(std::vector<Coordinates> &coords) { impl->coords = coords; }

void Block::setState(int newState) { impl->rotationState = newState; }

bool Block::isHeavy() { return impl->isHeavy; }

vector<vector<int>> Block::right() 
{
    vector<vector<int>> transform = {{1, 0}, {1, 0}, {1, 0}, {1, 0}};
    return transform;
}

vector<vector<int>> Block::left() 
{
    vector<vector<int>> transform = {{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}};
    return transform;
}

vector<vector<int>> Block::down() 
{
    vector<vector<int>> transform = {{0, 1}, {0, 1}, {0, 1}, {0, 1}};
    return transform;
}


void Block::decay()
{

}

void Block::updateCoords(Coordinates oldCoords, Coordinates newCoords=Coordinates{-1, -1})
{
    int len = impl->coords.size();
    for (int i = 0; i < len; i++)
    {
        if (impl->coords[i] == oldCoords) impl->coords[i] = newCoords;
    }
}

/*vector<vector<int>> Block::spawnTransformation(vector<vector<int>> coords, map<int, vector<vector<int>>> spawnState, int currState) {
    vector<vector<int>> retVal;
    for (int i = 0; i < 4; i++) {
        vector<int> temp = {-1 * (spawnState[currState][i][0] - coords[i][0]),
            -1 * (spawnState[currState][i][1] - coords[i][1])};
        retVal.emplace_back(temp);
    };
    return retVal;
} */

vector<vector<int>> Block::vviAddition(const vector<vector<int>> a, const vector<vector<int>> b) {
    vector<vector<int>> retVal;
    for (int i = 0; i < 4; i++) {
        vector<int> temp = {a[i][0] + b[i][0],
            a[i][1] + b[i][1]};
        retVal.emplace_back(temp);
    };
    return retVal;
}

vector<vector<int>> Block::vviSubtraction(const vector<vector<int>> a, const  vector<vector<int>> b) {
    vector<vector<int>> retVal;
    for (int i = 0; i < 4; i++) {
        vector<int> temp = {a[i][0] - b[i][0],
            a[i][1] - b[i][1]};
        retVal.emplace_back(temp);
    };
    return retVal;
}

vector<vector<int>> Block::getVVICoords() {
    vector<vector<int>> retVal;
    vector<Coordinates> tempC = getCoords();
    for (int i = 0; i < 4; i++) {
        vector<int> temp = {tempC[i].getX(), tempC[i].getY()};
        retVal.emplace_back(temp);
    }
    return retVal;
}