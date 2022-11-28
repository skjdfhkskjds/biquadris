#include "coordinates.h"
#include "board.h"

Coordinates::Coordinates(int x, int y, int width) : x{x}, y {y}, width{width} {}

int Coordinates::getPosition() { return ((width * y) + x); }
