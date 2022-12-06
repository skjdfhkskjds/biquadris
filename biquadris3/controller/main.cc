#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "../common/coordinates.h"
#include "../model/blocks/iblock.h"
#include "../model/blocks/jblock.h"
#include "../model/blocks/lblock.h"
#include "../model/blocks/oblock.h"
#include "../model/blocks/sblock.h"
#include "../model/blocks/tblock.h"
#include "../model/blocks/zblock.h"
#include "../model/player.h"
#include "../model/board/board.h"
#include "../model/board/board.h"
#include "../model/levels/level.h"
#include "../model/levels/levelone.h"
#include "../model/levels/leveltwo.h"
#include "../model/levels/levelthree.h"
#include "../model/levels/levelfour.h"
using namespace std;

const int width = 11;
const int height = 18;

void pPrint(vector<char> state) {
    for (int i = 0; i < width; i ++) {
        cout << '-';
    }
    cout << endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << state[y*width + x];
        }
        cout << endl;
    }
    for (int i = 0; i < width; i ++) {
        cout << '-';
    }
    cout << endl;
}

int main(int argc, char ** argv)
{
    vector<char> seq = {'I', 'J', 'L', 'O', 'S', 'Z', 'T'};
    Player p1(seq, 0, 1);
    cout << "Level:" << p1.getLevel() << endl;
    cout << "Score:" << p1.getScore() << endl;
    pPrint(p1.getState());
    p1.playTurn("right");
    pPrint(p1.getState());
    p1.playTurn("down");
    pPrint(p1.getState());
    p1.playTurn("clockwise");
    pPrint(p1.getState());
    p1.playTurn("drop");
    pPrint(p1.getState());
}
