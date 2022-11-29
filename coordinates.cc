#include "coordinates.h"
#include "board.h"

using namespace std;

Coordinates::Coordinates(int x, int y) : x{x}, y {y} {}

int Coordinates::getPosition() { return ((width * y) + x); }

void Coordinates::updateCoords(int deltaX, int deltaY)
{
    x += deltaX;
    y += deltaY;
}

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


Coordinates::Iterator Coordinates::beginLine(int row)
{
    return Iterator(make_unique<Coordinates>(0, row));
}

Coordinates::Iterator Coordinates::endLine(int row)
{
    return Iterator(make_unique<Coordinates>(width, row));
}