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

void updateMachine(vector<Coordinates &> coords, vector<vector<int>> trans) {
    for (int i = 0; i < 4; i++) {
        coords[i].update(trans[i][0], trans[i][1]);
    };
}

int main(int argc, char ** argv)
{
    IBlock myBlock(0); 
    vector<Coordinates &> fakeBlock;
    for (int i = 0; i < 4; i++) {
        Coordinates temp(myBlock.getCoords()[i].getX(), myBlock.getCoords()[i].getY());
        fakeBlock.emplace_back(temp);
    }
    //cout << myBlock.getLvl();
    cout << myBlock.getChar();
    
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.right());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.left());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.down());
    updateMachine(fakeBlock, myBlock.right());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
     updateMachine(fakeBlock, myBlock.down());
    updateMachine(fakeBlock, myBlock.right());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
    updateMachine(fakeBlock, myBlock.clockwise());
    psuedoPrint(myBlock.getCoords(), myBlock.getChar());
}
