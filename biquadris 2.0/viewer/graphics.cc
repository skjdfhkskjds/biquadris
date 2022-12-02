#include "graphics.h"
#include "../model/player.h"
#include "../model/board.h"
#include <memory>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
const int width = 11;
const int height = 18;

/*
class Graphics : public Observer
{
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::vector<char>> oldStates;
    std::vector<std::vector<char>> newStates;
public:
    Graphics(std::vector<std::shared_ptr<Player>> players);
    ~Graphics();
    void notify() override;
};
*/

//returns a map of index to char, representing all the differences between a player's old boardstate to it's new boardstate.
map<int,char> Graphics::getDeltas(int p) {  // takes int p, 0 for player1, 1 for player2
    map<int,char> deltas;
    for(int i = 0; i < width * height; i++) {
        char curr = newStates[p][i];
        if (curr != oldStates[p][i]) {
            deltas[i] = curr;
        }
    }
    oldStates[p] = newStates[p];
}

void Graphics::notify() {
    map<int,char> p1Deltas = getDeltas(0);
    map<int,char> p2Deltas = getDeltas(1);
    //something render deltas
    for (auto i : p1Deltas) {
        //render i.second at i.first
    }
    for (auto i : p2Deltas) {
        //render i.second at i.first
    }
}

Graphics::Graphics(vector<shared_ptr<Player>> players) : players{players} {
    newStates[0] = players[0]->getState();
    newStates[1] = players[1]->getState();
    for(int i = 0; i < width * height; i++) {
        oldStates[0][i] = '~';;
        oldStates[1][i] = '~';
    }
}