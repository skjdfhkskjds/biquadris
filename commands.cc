#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "commands.h"

using namespace std;

// constructor declares preexisting commands with a map
Commands::Commands()
{
    // defining the built in vectors
    vector<int> left = {LEFT};
    vector<int> right = {RIGHT};
    vector<int> down = {DOWN};
    vector<int> clockwise = {CLOCKWISE};
    vector<int> counterclockwise = {COUNTERCLOCKWISE};
    vector<int> drop = {DROP};
    vector<int> levelup = {LEVELUP};
    vector<int> leveldown = {LEVELDOWN};
    vector<int> norandom = {NORANDOM};
    vector<int> random = {RANDOM};
    vector<int> sequence = {SEQUENCE};
    vector<int> I = {I};
    vector<int> J = {J};
    vector<int> L = {L};
    vector<int> restart = {RESTART};

    // adding the vectors to the map
    commands = { {"left", left}, {"right", right}, {"down", down}, 
    {"clockwise", clockwise}, {"counterclockwise", counterclockwise}, 
    {"drop", drop}, {"levelup", levelup}, {"leveldown", leveldown}, 
    {"norandom", norandom}, {"random", random}, {"sequence", sequence}, 
    {"I", I}, {"J", J}, {"L", L}, {"restart", restart}};
}

// interprets the command they pass in
void Commands::interpret(string &command)
{
    // throws command_not_found exception, handle later
    if (commands.count(command) == 0) throw;

    // parse numbers in the command first, create loop to iterate n times, and handle exceptions
    // search letter by letter to deal with incomplete phrases
    // THIS COULD ALSO MEAN SHORTENING THE EXISTING KEYS TO FIT MINIMUM COMMAND LENGTH

    vector<int> commandsToRun = commands[command];
    for (int c : commandsToRun)
    {
        // case switch through the command options
    }
}

// returns true if successful, false otherwise
bool Commands::rename(string &existing, string &newName)
{
    // throws command_not_found
    if (commands.count(existing) == 0) throw;

    commands[newName] = commands[existing];
    commands.erase(existing);
}

// returns true if successful, false otherwise
bool Commands::addMacro(string &command)
{
    // throws command_already_exists
    if (commands.count(command) != 0) throw;

    vector<int> newCommand;
    string input;

    // gets input until user types done or types an invalid command
    while (cin >> input)
    {
        // checks conditions
        if (command == "done" || commands.count(command) == 0 ) break;

        // adds new command
        newCommand.emplace_back(commands[command]);
    }

    // adds new command vector to map with key "command"
    commands[command] = newCommand;
}
