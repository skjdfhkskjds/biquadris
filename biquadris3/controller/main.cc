#include <iostream>
#include <vector>
#include <string>
// #include "game.h"
#include "../misc/coordinates.h"

using namespace std;

void print(vector<Coordinates> coords)
{
    for (auto &c : coords)
    {
        c.print();
    }
}

vector<Coordinates> foo(vector<Coordinates> coords)
{
    for (auto &c : coords)
    {
        c.update(c.getX() + 1, c.getY() + 1);
    }
    return coords;
}

int main(int argc, char ** argv)
{
    vector<Coordinates> coords;
    Coordinates a{0, 0};
    Coordinates b{1, 0};
    Coordinates c{1, 1};
    Coordinates d{2, 1};
    
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);

    print(coords);
    coords = foo(coords);
    print(coords);

    // for (int i = 1; i < argc; i++)
    // {

    // }
    // Game g{};
    // int winner = g.run();
}
