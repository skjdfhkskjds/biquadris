#ifndef _COMMANDS_
#define _COMMANDS_

#include <map>
#include <string>
#include <vector>

using namespace std;

class Commands
{
    // base commands
    const enum {LEFT=0, RIGHT, DOWN, CLOCKWISE, COUNTERCLOCKWISE, DROP, LEVELUP, LEVELDOWN, NORANDOM, RANDOM, SEQUENCE, I, J, L, RESTART};
    
    // vector containing all the commands
    map<string, vector<int>> commands;

public:
    Commands() noexcept;
    void interpret(string &command);
    bool rename(string &existing, string &newName);
    bool addMacro(string &command);
};

#endif
