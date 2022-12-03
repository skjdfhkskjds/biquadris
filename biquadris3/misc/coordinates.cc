#include <iostream>
#include "coordinates.h"

#define width 11

Coordinates::Coordinates(int x, int y) : x{x}, y{y} {}

int Coordinates::index() { return ((width * y) + x); }

void Coordinates::update(int deltaX, int deltaY)
{
    x += deltaX;
    y += deltaY;
}

int Coordinates::getX() { return x; }

int Coordinates::getY() { return y; }

bool Coordinates::removed() { return (x == -1 && y == -1); }

void Coordinates::print()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
