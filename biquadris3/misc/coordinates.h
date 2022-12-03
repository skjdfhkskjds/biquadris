#ifndef _COORDS_
#define _COORDS_

class Coordinates
{
    int x, y;

public:
    Coordinates(int x, int y);

    int index();                         // returns the 1D mapped index of (x, y)
    void update(int deltaX, int deltaY); // updates the values of (x, y)
    int getX();                          // returns x
    int getY();                          // returns y
    bool removed();                      // returns whether the coordinate has been removed

    void print(); // prints the coordinates in a formatted way (for testing)
};

#endif
