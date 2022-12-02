#include <iostream>
#include "coordinates.h"

#define width 11
#define height 18

using namespace std;

int main()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Coordinates c{x, y};
            cout << "(" << c.getX() << ", " << c.getY() << ")" << endl;
            cout << "[" << c.index() << "]" << endl;
        }
    }
    Coordinates c{0, 0};
    c.update(1, 1);
    cout << "(" << c.getX() << ", " << c.getY() << ")" << endl;
    cout << "[" << c.index() << "]" << endl;
}
