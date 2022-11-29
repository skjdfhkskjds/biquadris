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
    int getX();
    int getY();
    
    class Iterator
    {
        std::unique_ptr<Coordinates> coord;
    public:
        explicit Iterator(std::unique_ptr<Coordinates> coord) noexcept;
        int operator*() noexcept;
        Iterator & operator++() noexcept;
        bool operator==(const Iterator &other) noexcept;
        bool operator!=(const Iterator &other) noexcept;

        friend class Coordinates;
    };

    Iterator begin() noexcept;
    Iterator end() noexcept;

    Iterator beginLine() noexcept;
    Iterator endLine() noexcept;
};

#endif
