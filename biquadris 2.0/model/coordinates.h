#ifndef _COORDS_
#define _COORDS_

class Coordinates
{
    int x, y;

public:
    Coordinates(int x, int y);

    int index();                 // returns the 1D mapped index of (x, y)
    void update(int x2, int y2); // updates the values of (x, y)
    int getX();                  // returns x
    int getY();                  // returns y
};

#endif
