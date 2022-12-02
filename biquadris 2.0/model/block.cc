#include <vector>
#include <memory>
#include "block.h"
#include "coordinates.h"

using namespace std;

struct Block::BlockImpl
{
    vector<unique_ptr<Coordinates>> coords;
    int blockType, age, ageLimit, rotationState;
    char c;

    BlockImpl();
    ~BlockImpl() = default;

    bool isSafe();
    void update(vector<vector<int>>& coordChanges);
    void setCoord(Coordinates& newCoord);
    vector<vector<int>> getCoords();
};

Block::BlockImpl::BlockImpl(): blockType{0}, age{0}, ageLimit{-1}, rotationState{0} {};

Block::Block() : impl{new Block::BlockImpl} {}

Block::~Block() = default;

vector<vector<int>> Block::BlockImpl::getCoords() {
    vector<vector<int>> v;
    int len = coords.size();
    for (int i = 0; i < len; i++) {
        vector<int> vi = {coords[i]->getX(), coords[i]->getY()};
        v.emplace_back(vi);
    }
    return v;
}


// check new coord safety right before update

bool Block::BlockImpl::isSafe()
{
    // check if any part of the piece is off the board first

    for (auto&& coord : coords)
    {
        // if (!isSafe(coord)) return false; CALL BOARDSTATE'S isSafe()
    }
    return true;
}

void Block::BlockImpl::update(vector<vector<int>>& coordChanges)
{
    int i = 0;
    for (auto&& coord : coords)
    {
        coord->update(coordChanges[i][0], coordChanges[i][1]);
        i++;
    }
}

void Block::BlockImpl::setCoord(Coordinates& newCoord)
{
    coords.emplace_back(make_unique<Coordinates>(newCoord));
}

bool Block::isSafe()
{
    impl->isSafe();
}

int Block::getState() { return impl->rotationState; }

void Block::setState(int newState) { impl->rotationState = newState; }

void Block::setChar(char newChar) {impl->c = newChar;}

void Block::setCoords(vector<Coordinates>& coords)
{
    for (auto coord : coords)
    {
        impl->setCoord(coord);
    }
}

void Block::update(vector<vector<int>>& coordChanges)
{
    impl->update(coordChanges);
}

void Block::shiftRight() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    vector<vector<int>> changes = {{1, 0}, {1, 0}, {1, 0}, {1, 0}};
    update(changes);
}

void Block::shiftLeft() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    vector<vector<int>> changes = {{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}};
    update(changes);
}

void Block::shiftDown() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE update
    vector<vector<int>> changes = {{0, 1}, {0, 1}, {0, 1}, {0, 1}};
    update(changes);
}

char Block::getBlockChar() {
    return impl->c;
}
 vector<vector<int>> Block::getCoords() {
    return impl->getCoords();
 }
