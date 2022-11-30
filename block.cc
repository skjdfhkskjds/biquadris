#include <vector>
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
    void updateCoords(vector<vector<int>>& coordChanges);
};

Block::BlockImpl::BlockImpl(): blockType{0}, age{0}, ageLimit{-1}, rotationState{0} {};

Block::Block() : pImpl{new Block::BlockImpl} {}

Block::~Block() = default;


// check new coord safety right before updateCoords

bool Block::BlockImpl::isSafe()
{
    // check if any part of the piece is off the board first

    for (auto&& coord : coords)
    {
        // if (!isSafe(coord)) return false; CALL BOARDSTATE'S isSafe()
    }
    return true;
}

void Block::BlockImpl::updateCoords(vector<vector<int>>& coordChanges)
{
    int i = 0;
    for (auto&& coord : coords)
    {
        coord->updateCoords(coordChanges[i][0], coordChanges[i][1]);
        i++;
    }
}

bool Block::isSafe()
{
    pImpl->isSafe();
}

int Block::getState() { return pImpl->rotationState; }

void Block::setState(int newState) { pImpl->rotationState = newState; }

void Block::updateCoords(vector<vector<int>>& coordChanges)
{
    pImpl->updateCoords(coordChanges);
}

void Block::shiftRight() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    vector<vector<int>> changes = {{1, 0}, {1, 0}, {1, 0}, {1, 0}};
    updateCoords(changes);
}

void Block::shiftLeft() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    vector<vector<int>> changes = {{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}};
    updateCoords(changes);
}
