#include "controller/game.h"
#include "model/player.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "common/exceptions.h"
using namespace std;
/*
bonus flags:
-macro
-decay
-autolevel
-multieffects
*/


int main(int argc, char ** argv) {

    vector<bool> flagStates(5, false);
    string file1 = "sequence1.txt";
    string file2 = "sequence2.txt";
    int seed = 0;
    int startLvl = 0;
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-text")
        {
           flagStates[0] = true;
        }
        else if (argv[i] == "-seed")
        {
            i++;
            istringstream iss{argv[i]};
            if (iss >> seed) {
            } else {
                //throw something
            }
        }
        else if (argv[i] == "-scriptfile")
        {
            i++;
            file1 = argv[i];
        }
        else if (argv[i] == "-scriptfile2")
        {
            i++;
            file2 = argv[i];
        }
        else if (argv[i] == "-startlevel")
        {
            i++;
            istringstream iss{argv[i]};
            if (iss >> startLvl) {
            } else {
                //throw something
            }
        } 
        else if (argv[i] == "-macro")
        {
            flagStates[1] = true;
        } 
        else if (argv[i] == "-decay")
        {
            flagStates[2] = true;
        }
        else if (argv[i] == "-autolevel")
        {
            flagStates[3] = true;
        }
        else if (argv[i] == "-multieffects")
        {
            flagStates[4] = true;
        }
        else
        {
            string command = argv[i];
            throw command_not_found(command);
        }
    }
    Game biquadris(seed, startLvl, {file1, file2}, flagStates);
    biquadris.playTurn();
}