#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
//#include "common/exceptions.h"
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
    for (int i = 1; i < argc; i++)
    {
	cout << argv[i] << endl;
    string arg1 = argv[i];
    string arg2;
        if (arg1 == "-text")
        {
           flagStates[0] = true;
           cout << "-text" << endl;
        }
        else if (arg1 == "-seed")
        {
            i++;
            arg2 = argv[i];
            istringstream iss{arg2};
            if (iss >> seed) {
            } else {
                //throw something
            }
            cout << "-seed" << endl;
            cout << argv[i] << endl;
        }
        else if (arg1 == "-scriptfile")
        {
            i++;
            file1 = argv[i];
            cout << "-scriptfile" << endl;
            cout << argv[i] << endl;
        }
        else if (arg1 == "-scriptfile2")
        {
            i++;
            file2 = argv[i];
            cout << "-scriptfile2" << endl;
            cout << argv[i] << endl;
        }
        else if (arg1 == "-startlevel")
        {
            i++;
            arg2 = argv[i];
            istringstream iss{arg2};
            if (iss >> startLvl) {
                cout << "-startlevel" << endl;
                cout << argv[i] << endl;
            } else {
                //throw something
                cout << ":(";
            }
        } 
        else if (arg1 == "-macro")
        {
            flagStates[1] = true;
            cout << "-macro" << endl;
        } 
        else if (arg1 == "-decay")
        {
            flagStates[2] = true;
            cout << "-decay" << endl;
        }
        else if (arg1 == "-autolevel")
        {
            flagStates[3] = true;
            cout << "-autolevel" << endl;
        }
        else if (arg1 == "-multieffects")
        {
            flagStates[4] = true;
            cout << "-multieffects" << endl;
        }
        else
        {
            string command = argv[i];
            //throw command_not_found(command);
            cout << "):";
        }
    }
    for (auto x : flagStates) {
            cout << x << endl;
    }
}
