#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include "commands.h"
#include "../viewer/text.h"
#include "../viewer/observer.h"
#include "../viewer/graphics.h"
#include <vector>
#include "game.h"
#include "../misc/exceptions.h"
using namespace std;

int main(int argc, char **argv)
{
    vector<string> seq;
    string file1 = "sequence1.txt";
    string file2 = "sequence2.txt";
    int seed = 0;
    int startLvl = 0;
    bool graphics = true;
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-text")
        {
            bool graphics = false;
        }
        else if (argv[i] == "-seed")
        {
            i++;
            seed = stoi(argv[i]);
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
            startLvl = stoi(argv[i]);
        }
        else
        {
            string command = argv[i];
            throw command_not_found(command);
        }
    }
    seq.emplace_back(file1);
    seq.emplace_back(file2);

    Game bisexual(seq, seed, startLvl);
    string s;
    Commands commander;
    if (graphics) {
        
    }
    while (cin >> s)
    {
        istringstream iss{s};
        commander.interpret(s);
    }
    if (graphics) {
        //do stuff to create graphics;
    }
    //do stuff to create text
}
