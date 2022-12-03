#include "block.h"

using namespace std;

struct Block::BlockImpl
{
    char c;
    int lvl, age, maxAge, rotationState;
    std::vector<Coordinates &> coords;

    BlockImpl(char c, int lvl);
    ~BlockImpl() = default;
    
    unique_ptr<Block> makeBlock(); // returns a block of type c

    void update(vector<vector<int>> transform);
    Coordinates &getCoords();
};

Block::BlockImpl::BlockImpl(char c, int lvl): lvl{lvl}, age{0}, maxAge{-1}, rotationState{0}, c{c} {};

void Block::BlockImpl::update(vector<vector<int>> transform)
{
    int i = 0;
    for (Coordinates & coord : coords)
    {
        coord.update(transform[i][0], transform[i][1]);
        i++;
    }
}

Block::Block(char c, int lvl) : impl{make_unique<Block::BlockImpl>(c, lvl)} {}

int Block::getState() { return impl->rotationState; }

char Block::getChar() { return impl->c; }

int Block::getLvl() { return impl->lvl; }

vector<Coordinates &> Block::getCoords() { return impl->coords; }

void Block::setCoords(std::vector<Coordinates> &coords) { }

void Block::update(vector<vector<int>> transform) { impl->update(transform); }

void Block::right() 
{
    vector<vector<int>> changes = {{1, 0}, {1, 0}, {1, 0}, {1, 0}};
    update(changes);
}

void Block::left() 
{
    vector<vector<int>> changes = {{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}};
    update(changes);
}

void Block::down() 
{
    vector<vector<int>> changes = {{0, 1}, {0, 1}, {0, 1}, {0, 1}};
    update(changes);
}

void Block::counterClockwise()
{
    for (int i = 0; i < 3; i++)
    {
        clockwise();
    }
}

void Block::decay()
{

}
