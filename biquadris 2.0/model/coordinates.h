#ifndef _COORDS_
#define _COORDS_

class Coordinates
{
    const int width = 11;
    int x, y;
public:
    Coordinates(int x, int y);

    int index();
    void update(int x2, int y2);
    int getX();
    int getY();
};

#endif
