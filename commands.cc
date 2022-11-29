#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "commands.h"
#include <sstream>

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
    vector<int> O = {O};
    vector<int> S = {S};
    vector<int> Z = {Z};
    vector<int> T = {T};
    vector<int> restart = {RESTART};

    // adding the vectors to the map
    commands = { {"left", left}, {"right", right}, {"down", down}, 
    {"clockwise", clockwise}, {"counterclockwise", counterclockwise}, 
    {"drop", drop}, {"levelup", levelup}, {"leveldown", leveldown}, 
    {"norandom", norandom}, {"random", random}, {"sequence", sequence}, 
    {"I", I}, {"J", J}, {"L", L}, {"O", O}, {"S", S}, {"Z", Z}, {"T", T}, {"restart", restart}};

    //non multiplicative commands
    nonMultCommands = {"restart", "hint", "norandom", "random"}; 
}

// interprets the command they pass in
void Commands::interpret(string &command)
{
    // throws command_not_found exception, handle later //dom: I think we can handle this in our stringConverter
    if (commands.count(command) == 0) throw;

    // parse numbers in the command first, create loop to iterate n times, and handle exceptions
    // search letter by letter to deal with incomplete phrases
    // THIS COULD ALSO MEAN SHORTENING THE EXISTING KEYS TO FIT MINIMUM COMMAND LENGTH

    // ask dom to read in letter by letter including numbers for repetition

    vector<int> commandsToRun = commands[command];
    string file;
    for (int c : commandsToRun)
    {
        switch (c)
        {
        case 0:
            //left();
            break;
        case 1:
            //right();
            break;
        case 2:
            //down();
            break;
        case 3:
            //clockwise();
            break;
        case 4:
            //counterclockwise();
            break;
        case 5:
            //drop();
            break;
        case 6:
            //levelup();
            break;
        case 7:
            //leveldown();
            break;
        case 8:
            cin >> file;
            std::ifstream ifs{file};
            if (!ifs.good()) {
                throw file_not_found(file);
            }
            //norandom(file);
            break;
        case 9:
            //random();
            break;
        case 10:
            cin >> file;
            //sequence(file);
            break;
        case 11:
            //I();
            break;
        case 12:
            //J();
            break;
        case 13:
            //L();
            break;
        case 14:
            //O();
            break;
        case 15:
            //S();
            break;
        case 16:
            //Z();
            break;
        case 17:
            //T();
            break;
        case 18:
            //restart();
            break;
        default:
            break;
        }
        // case switch through the command options

        // if command is any of the run once only functions, change runOnce to true
    }
}

void Commands::rawInterpret(string &rawCommand) //doesn't handle macros including any of the nonMultiplier viable commands
{
    //rawInterpret is called by main on the first word 
    int multiplier = 0;
    string commandName;
    std::istringstream iss{rawCommand};
    iss >> multiplier;
    iss >> commandName;
    commandName = stringConvert(commandName);
    for (string i : nonMultCommands) 
    {
        if (commandName == i)
        {
            interpret(commandName);
            return;
        }
    }
    //if (commandName == "sequence") 
    /*sequence works funny because it takes in a file name, but also can be called multiple times*/
    if (multiplier == 1) 
    {
        interpret(commandName);
    } 
    else 
    {
        for (int i = 0; i < multiplier; i++) 
        {
            interpret(commandName);
            return;
        }
    }
}

string Commands::stringConvert(string &abbrv)
{
    //recieves a string, returns the full name of a command
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
