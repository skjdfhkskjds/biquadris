#ifndef _COORDS_
#define _COORDS_

class Coordinates
{
    int x, y, width;

public:
    Coordinates(int x, int y, int width);
    int getPosition(); // returns the position of (x, y) on the 1D vector
};

#endif
