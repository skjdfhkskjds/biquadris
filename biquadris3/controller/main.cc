#include <iostream>
#include <vector>
#include <string>
// #include "game.h"
#include "../common/coordinates.h"
#include "../model/blocks/iblock.h"
#include "../model/blocks/jblock.h"
#include "../model/blocks/lblock.h"
#include "../model/blocks/oblock.h"
#include "../model/blocks/sblock.h"
#include "../model/blocks/tblock.h"
#include "../model/blocks/zblock.h"
using namespace std;

const int width = 11;
const int height = 18;

void print(Coordinates &c)
{
    cout << "(" << c.getX() << ", " << c.getY() << ")" << endl;
}

void print(vector<Coordinates &> coords)
{
    for (Coordinates &c : coords)
    {
        print(c);
    }
}

vector<Coordinates &> foo(vector<Coordinates &> coords)
{
    for (Coordinates &c : coords)
    {
        c.update(1, 1);
    }
    return coords;
}

void psuedoPrint(vector<Coordinates> coords, char c) {
    for (int x = 0; x < width; x++) {
        cout << "-";
    }
    int len = coords.size();
    int mybool = true;
    cout << endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int z = 0; z < len; z++) {
                if ((y == coords[z].getY()) && (x == coords[z].getX())) {
                    cout << c;
                    mybool = false;
                    break;
                }
            }
            if (mybool) {
                cout << ' ';
            }
            mybool = true;
        }
        cout << endl;
    }
    for (int x = 0; x < width; x++) {
        cout << "-";
    }
    cout << endl;
}

int main(int argc, char ** argv)
{
    IBlock myBlock(0); 
    cout << myBlock.getLvl();
    cout << myBlock.fullCleared();
    //cout <<
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.right();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.left();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.down();
    myBlock.right();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.down();
    myBlock.right();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.clockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.clockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.clockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.clockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.counterClockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.counterClockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.counterClockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    myBlock.counterClockwise();
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());

}