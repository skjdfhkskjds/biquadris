#include "text.h"
#include "../model/player.h"
#include "../model/board.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
const int width = 11;
const int height = 18;

void divider() {
    cout << "      ";
}

void pagebreak() {
    for (int x = 0; x < width; x++) {
        cout << "-";
    }
    divider();
    for (int x = 0; x < width; x++) {
        cout << "-";
    }
    cout <<endl;
}

void Text::notify()
{
    shared_ptr<Player> p1 = players[0];//shit to get the boardstate
    shared_ptr<Player> p2 = players[1];//shit to get the boardstate
    vector<char> b1 = p1->getState();
    vector<char> b2 = p2->getState();

    //print p1 level
    cout << "Level:    " << p1->getLevel();
    divider();
    //print p2 level
    cout << "Level:    " << p2->getLevel();
    cout << endl; 

    //print p1 score
    cout <<"Score:    " << p1->getScore();
    divider();
    //print p2 score
    cout <<"Score:    " << p2->getScore();
    cout <<  endl; 
    
    //print pagebreak at top
    pagebreak();

    //print both board states
    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++){
            cout<< b1[y*width + x];
        }
        divider();
        for (int x = 0; x < width; x++){
            cout<< b2[y*width + x];
        }
        cout << endl;
    }

    //print pagebreak at top;
    pagebreak();

    cout << "Next:     ";
    divider();
    cout << "Next:     ";
    //create a function that uses p1->getNextBlockChar(), and prints the block on a 2x4
}

