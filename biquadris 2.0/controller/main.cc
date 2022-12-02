#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "commands.h"
using namespace std;

int main(int argc, char **argv)

{
    bool onlyText = false;
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-text")
        {
            bool onlyText = true;
        }
        else if (argv[i] == "-seed")
        {
            i++;
            int seed = stoi(argv[i]);
        }
        else if (argv[i] == "-scriptfile")
        {
            i++;
            ifstream file1{argv[i]};
        }
        else if (argv[i] == "-scriptfile2")
        {
            i++;
            ifstream file2{argv[i]};
        }
        else if (argv[i] == "-startlevel")
        {
            i++;
            int level = stoi(argv[i]);
        }
        else
        { // show text and graphics
        }
    }
    string s;
    Commands commander;
    while (cin >> s) {
        istringstream iss{s};
        commander.interpret(s);
    }

}
