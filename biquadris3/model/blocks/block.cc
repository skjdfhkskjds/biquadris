#include "block.h"

using namespace std;

struct Block::BlockImpl
{
    char c;
    int lvl, age, maxAge, rotationState;
    bool isHeavy; // heavinesss based on level
    std::vector<Coordinates &> coords;

    BlockImpl(char c, int lvl);
    ~BlockImpl() = default;

    Coordinates &getCoords();
};

Block::BlockImpl::BlockImpl(char c, int lvl): lvl{lvl}, age{0}, maxAge{-1}, rotationState{0}, c{c}, isHeavy{(lvl >= 3) ? true : false} {};

Block::Block(char c, int lvl) : impl{make_unique<Block::BlockImpl>(c, lvl)} {}

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

vector<Coordinates &> Block::getCoords() { return impl->coords; }

void Block::setCoords(std::vector<Coordinates &> &coords) { impl->coords = coords; }

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
