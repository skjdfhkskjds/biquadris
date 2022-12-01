#include "coordinates.h"

Coordinates::Coordinates(int x, int y) : x{x}, y{y} {}

int Coordinates::index() { return ((width * y) + x); }

void Coordinates::update(int x2, int y2)
{
    x += x2;
    y += y2;
}

int Coordinates::getX() { return x; }

int Coordinates::getY() { return y; }
