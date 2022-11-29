#include "coordinates.h"
#include "board.h"

using namespace std;

Coordinates::Coordinates(int x, int y, int width) : x{x}, y {y}, width{width} {}

int Coordinates::getPosition() { return ((width * y) + x); }

Coordinates::Iterator::Iterator(std::unique_ptr<Coordinates> coord) : coord{move(coord)} {}

int Coordinates::Iterator::operator*()
{
    return coord->getPosition();
}

Coordinates::Iterator &Coordinates::Iterator::operator++()
{
    
    coord.reset();
    coord = make_unique<Coordinates>();
}