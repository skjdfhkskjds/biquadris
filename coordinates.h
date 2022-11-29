#ifndef _COORDS_
#define _COORDS_

#include <memory>

class Coordinates
{
    int x, y, width;

public:
    Coordinates(int x, int y, int width);
    int getPosition(); // returns the position of (x, y) on the 1D vector
    
    class Iterator
    {
        std::unique_ptr<Coordinates> coord;
    public:
        explicit Iterator(std::unique_ptr<Coordinates> coord);
        int operator*();
        Iterator & operator++();
        bool operator==(const Iterator &other);
        bool operator!=(const Iterator &other);

        friend class Coordinates;
    };

    Iterator begin();
    Iterator begin(Coordinates &rowStart);
    Iterator end();
};

#endif
