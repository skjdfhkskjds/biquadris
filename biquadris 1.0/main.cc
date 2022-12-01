#include <iostream>
#include <string>
#include <memory>
#include "player.h"
#include "exceptions.h"
#include "commands.h"

using namespace std;

int main(int argc, char **argv)
{
    Player p1;
    Player p2;
    Commands cmds;
    string command;
    while (cin >> command)
    {
        if (cin.fail())
        {
            cin.ignore();
            cin.clear();
        }
        try
        {
            cmds.interpret(command);
        }
        catch(const exception e)
        {
            cerr << e.what() << endl;
        }
    }
}
