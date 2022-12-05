#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "commands.h"
#include "../common/exceptions.h"
#include <sstream>

using namespace std;

vector<string> minUnique{"lef", "ri", "do", "cl", "co", "dr", "levelu", "leveld", "nor", "ra", "se", "I", "J", "L", "O", "S", "Z", "T", "re"};
vector<string> fullCommand{"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "I", "J", "L", "O", "S", "Z", "T", "restart"};

struct Commands::CommandsImpl
{
    // base commands
    const enum { LEFT = 0,
                 RIGHT,
                 DOWN,
                 CLOCKWISE,
                 COUNTERCLOCKWISE,
                 DROP,
                 LEVELUP,
                 LEVELDOWN,
                 NORANDOM,
                 RANDOM,
                 SEQUENCE,
                 I,
                 J,
                 L,
                 O,
                 S,
                 Z,
                 T,
                 RESTART };

    // vector containing all the commands
    map<string, vector<int>> commands;
    vector<string> nonMultCommands;

    CommandsImpl();
    ~CommandsImpl() = default;

    void interpret(string &command);
    void apply(string &command);
    void interpretEffect(string &Effect);
    string stringConvert(string &abbrv);
    bool rename(string &existing, string &newName);
    bool addMacro(string &command);
};

// constructs the impl and establishes the vector map
Commands::CommandsImpl::CommandsImpl()
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
    commands = {{"left", left}, {"right", right}, {"down", down}, {"clockwise", clockwise}, {"counterclockwise", counterclockwise}, {"drop", drop}, {"levelup", levelup}, {"leveldown", leveldown}, {"norandom", norandom}, {"random", random}, {"sequence", sequence}, {"I", I}, {"J", J}, {"L", L}, {"O", O}, {"S", S}, {"Z", Z}, {"T", T}, {"restart", restart}};

    // non multiplicative commands
    nonMultCommands = {"restart", "hint", "norandom", "random"};
}

// interprets the command they pass in
void Commands::CommandsImpl::apply(string &command)
{
    // throws command_not_found exception, handle later //dom: I think we can handle this in our stringConverter
    if (commands.count(command) == 0)
        throw;

    // parse numbers in the command first, create loop to iterate n times, and handle exceptions
    // search letter by letter to deal with incomplete phrases
    // THIS COULD ALSO MEAN SHORTENING THE EXISTING KEYS TO FIT MINIMUM COMMAND LENGTH

    vector<int> commandsToRun = commands[command];
    string file;
    for (int c : commandsToRun)
    {
        switch (c)
        {
        case 0:
            // left();
            break;
        case 1:
            // right();
            break;
        case 2:
            // down();
            break;
        case 3:
            // clockwise();
            break;
        case 4:
            // counterclockwise();
            break;
        case 5:
            // drop();
            break;
        case 6:
            // levelup();
            break;
        case 7:
            // leveldown();
            break;
        case 8:
        {
            cin >> file;
            ifstream ifs{file};
            if (!ifs.good())
            {
                throw file_not_found(file);
            }
            // norandom(file);
            break;
        }
        case 9:
            // random();
            break;
        case 10:
            cin >> file;
            // sequence(file);
            break;
        case 11:
            // I();
            break;
        case 12:
            // J();
            break;
        case 13:
            // L();
            break;
        case 14:
            // O();
            break;
        case 15:
            // S();
            break;
        case 16:
            // Z();
            break;
        case 17:
            // T();
            break;
        case 18:
            // restart();
            break;
        default:
            break;
        }
        // case switch through the command options

        // if command is any of the run once only functions, change runOnce to true
    }
}

void Commands::CommandsImpl::interpretEffect(string &effect)
{
}

void Commands::CommandsImpl::interpret(string &command) // doesn't handle macros including any of the nonMultiplier viable commands
{
    // rawInterpret is called by main on the first word
    int multiplier = 0;
    string commandName;
    std::istringstream iss{command};
    iss >> multiplier;
    iss >> commandName;
    commandName = stringConvert(commandName);
    for (string i : nonMultCommands)
    {
        if (commandName == i)
        {
            apply(commandName);
            return;
        }
    }
    // if (commandName == "sequence")
    /*sequence works funny because it takes in a file name, but also can be called multiple times*/
    if (multiplier == 1)
    {
        apply(commandName);
    }
    else
    {
        for (int i = 0; i < multiplier; i++)
            apply(commandName);
    }
}

string Commands::CommandsImpl::stringConvert(string &abbrv)
{
    int len = minUnique.size();
    string minStr;
    string maxStr;
    for (int i = 0; i < len; i++)
    {
        minStr = minUnique[i];
        maxStr = fullCommand[i];
        if ((abbrv.find(minStr) != string::npos) && (maxStr.find(abbrv) != string::npos))
        {
            return abbrv;
        }
    }
    throw command_not_found{abbrv};
}

// returns true if successful, false otherwise
bool Commands::CommandsImpl::rename(string &existing, string &newName)
{
    // throws command_not_found
    if (commands.count(existing) == 0)
        throw command_not_found{existing};

    // adds command to the existing map and erases the old key
    commands[newName] = commands[existing];
    commands.erase(existing);
}

// returns true if successful, false otherwise
bool Commands::CommandsImpl::addMacro(string &command)
{
    // throws command_already_exists
    if (commands.count(command) != 0)
        throw command_already_exists{command};

    // sets up variables for new commands
    vector<int> newCommand;
    string input;

    // gets input until user types done or types an invalid command
    while (cin >> input)
    {
        // checks conditions
        if (command == "done" || commands.count(command) == 0)
            break;

        // adds new command
        newCommand.emplace_back(commands[command]);
    }

    // adds new command vector to map with key "command"
    commands[command] = newCommand;
}

// Implementation for the Command class using impl

// constructor declares the impl
Commands::Commands() : impl{make_unique<Commands::CommandsImpl>()} {}

Commands::~Commands() = default;

void Commands::interpret(string &command) { impl->interpret(command); }

void Commands::apply(string &command) { impl->apply(command); }

bool Commands::rename(string &existing, string &newName) { impl->rename(existing, newName); }

bool Commands::addMacro(string &command) { impl->addMacro(command); }
