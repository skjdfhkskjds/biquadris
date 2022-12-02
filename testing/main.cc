#include <iostream>
#include "../biquadris 2.0/model/block.h"
#include "../biquadris 2.0/model/blocks/sblock.h"

#include <vector>

using namespace std;

void printCoords(std::vector<std::vector<int>> coords) {
    int len = coords.size();
    for (int i = 0; i < len; i++) {
     cout << "coord: " << i << ", x: " << coords[i][0] << ", y: " << coords[i][1] << "." << endl;
    }
};

void pCOG(std::vector<std::vector<int>> coords, char c) { //printCoordinatesOnGrid
    int width = 11;
    int height = 18;
    vector<char> grid;
    for (int i = 0; i < width; i++) cout << "-";
    cout <<endl;
    for (int i = 0; i < width * height; i++)
    {
        grid.emplace_back(' ');
    }
    for (int i = 0; i < width; i++) cout << "-";
    cout <<endl;
    int len = coords.size();
    for (int i = 0; i < len; i++) {
        grid[coords[i][0] + coords[i][1] * height] = c;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << grid[x + y * width];
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++) cout << "-";
    cout <<endl;
};

int main(int argc, char *argv[]) {
    SBlock s;
    printCoords(s.getCoords());
    pCOG(s.getCoords(), s.getChar());
    s.shiftRight();
    printCoords(s.getCoords());
    pCOG(s.getCoords(), s.getChar());
    s.shiftRight();
    printCoords(s.getCoords());
    pCOG(s.getCoords(), s.getChar());
    s.shiftDown();
    printCoords(s.getCoords());
    pCOG(s.getCoords(), s.getChar());
}