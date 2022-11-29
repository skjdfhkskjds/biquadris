#ifndef _COORDS_
#define _COORDS_

#include <memory>

class Coordinates
{
    const int width = 11;
    const int height = 18;
    int x, y;

public:
    Coordinates(int x, int y);
    int getPosition(); // returns the position of (x, y) on the 1D vector
    void updateCoords(int deltaX, int deltaY);
    
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
    Iterator end();

    Iterator beginLine(int row);
    Iterator endLine(int row);
};

#endif
