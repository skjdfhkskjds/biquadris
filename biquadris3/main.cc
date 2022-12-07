#include "controller/game.h"
#include "model/player.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "common/exceptions.h"
#include "viewer/observer.h"
#include "viewer/text.h"
#include "viewer/graphics.h"
using namespace std;
/*
bonus flags:
-macro
-decay
-autolevel
-multieffects
*/

int main(int argc, char **argv)
{

    vector<bool> flagStates(5, false);
    string file1 = "sequence1.txt";
    string file2 = "sequence2.txt";
    int seed = 0;
    int startLvl = 0;
    string argv1;
    string argv2;
    for (int i = 0; i < argc; i++)
    {
        argv1 = argv[i];
        if (argv1 == "-text")
        {
            flagStates[0] = true;
        }
        else if (argv1 == "-seed")
        {
            i++;
            argv2 = argv[i];
            istringstream iss{argv2};
            if (iss >> seed) {
            } else {
                throw arg_not_found(argv2);
            }
        }
        else if (argv1 == "-scriptfile")
        {
            i++;
            file1 = argv2;
        }
        else if (argv1 == "-scriptfile2")
        {
            i++;
            file2 = argv[i];
        }
        else if (argv1 == "-startlevel")
        {
            i++;
            argv2 = argv[i];
            istringstream iss{argv2};
            if (iss >> startLvl) {
            } else {
                throw arg_not_found(argv2);
            }
        } 
        else if (argv1 == "-macro")
        {
            flagStates[1] = true;
        } 
        else if (argv1 == "-decay")
        {
            flagStates[2] = true;
        }
        else if (argv1 == "-autolevel")
        {
            flagStates[3] = true;
        }
        else if (argv1 == "-multieffects")
        {
            flagStates[4] = true;
        }
        else
        {
            string command = argv[i];
            throw command_not_found(command);
        }
    }
    shared_ptr<Game> biquadris(new Game(seed, startLvl, {file1, file2}, flagStates));
    Text textObserver(biquadris);
    if (flagStates[0]) {
        Graphics graphicsObserver(biquadris);
    }
    biquadris->playTurn();
}