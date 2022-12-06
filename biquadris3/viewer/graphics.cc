#include "graphics.h"
#include "../model/player.h"
#include "../model/board.h"
#include "window.h"
#include <memory>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
const int width = 11;
const int height = 18;

//Xwindow xWindow(width * 2 + 6, height + 9);
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

//string color_vals[10]={"white", "black", "red", "green", "blue", "cyan", "yellow", "magenta", "orange", "brown"};

map<char,int> blockColour = {
    {'I', 5},   //cyan
    {'J', 4},   //blue
    {'L', 8},   //orange
    {'O', 6},   //yellow
    {'S', 3},   //green
    {'Z', 2},    //red
    {'T', 7} //magenta
}

void Graphics::notify() {
    map<int,char> p1Deltas = getDeltas(0);
    map<int,char> p2Deltas = getDeltas(1);
    int p1Score = players[0].getScore();
    int p1Lvl = players[0].getLevel();
    int p2Score = players[1].getScore();
    int p2Lvl = plyaer[1].getLevel();
    //update text and next block each time
    xWindow.drawString(0, 0, "Level:     ");
    xWindow.drawString(0, width - 1, to_string(p1Lvl));
    xWindow.drawString(0, width + 6, "Level:     ");
    xWindow.drawString(0, width * 2 + 6 - 1, to_string(p1Lvl));
    //something render deltas
    int x;
    int y;
    for (auto i : p1Deltas) {
        //render i.second at i.first
        x = i.first % width;
        y = (i.first / width) + 3;
        xWindow.fillRectangle(x, y, 1, 1, blockColour[i.second]);
    }
    for (auto i : p2Deltas) {
        //render i.second at i.first
        x = (i.first % width) + width + 6;
        y = (i.first / width) + 3;
        xWindow.fillRectangle(x, y, 1, 1, blockColour[i.second]);
    }
}

Graphics::Graphics(shared_ptr<Game> game, Xwindow xWindow) : game{game}, xWindow{xWindow} {
    players.emplace_back(game->getPlayers[0]);
    players.emplace_back(game->getPlayers[1]);
    newStates[0] = players[0]->getState();
    newStates[1] = players[1]->getState();
    for(int i = 0; i < width * height; i++) {
        oldStates[0][i] = '~';;
        oldStates[1][i] = '~';
    }
}