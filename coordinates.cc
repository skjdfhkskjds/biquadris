#include "coordinates.h"
#include "board.h"

using namespace std;

Coordinates::Coordinates(int x, int y) : x{x}, y {y} {}

int Coordinates::getPosition() { return ((width * y) + x); }

void Coordinates::updateCoords(int newX, int newY)
{
    x = newX;
    y = newY;
}

int Coordinates::getX() { return x; }
int Coordinates::getY() { return y; }

Coordinates::Iterator::Iterator(std::unique_ptr<Coordinates> coord) : coord{move(coord)} {}

int Coordinates::Iterator::operator*()
{
    return coord->getPosition();
}

Coordinates::Iterator &Coordinates::Iterator::operator++()
{
    int x = coord->x;
    int y = coord->y;
    if (x == coord->width)
    {
        // set to -1 so that x + 1 returns 0
        x = -1;
        y++;
    }
    
    coord.reset();
    
    coord = make_unique<Coordinates>(x + 1, y);
}

bool Coordinates::Iterator::operator==(const Coordinates::Iterator &other)
{
    return coord == other.coord;
}

bool Coordinates::Iterator::operator!=(const Coordinates::Iterator &other)
{
    return !(*this == other);
}

Coordinates::Iterator Coordinates::begin() 
{ 
    return Iterator(make_unique<Coordinates>(0, 3));
}

Coordinates::Iterator Coordinates::end()
{
    return Iterator(make_unique<Coordinates>(width, height));
}

Coordinates::Iterator Coordinates::beginLine()
{
    return Iterator(make_unique<Coordinates>(0, y));
}

Coordinates::Iterator Coordinates::endLine()
{
    return Iterator(make_unique<Coordinates>(width, y));
}
