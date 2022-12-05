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

static vector<string> minUnique{"lef", "ri", "do", "cl", "co", "dr", "levelu", "leveld", "nor", "ra", "se", "I", "J", "L", "O", "S", "Z", "T", "re"};
static vector<string> fullCommand{"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "I", "J", "L", "O", "S", "Z", "T", "restart"};

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
    vector<int> Iblock = {I};
    vector<int> Jblock = {J};
    vector<int> Lblock = {L};
    vector<int> Oblock = {O};
    vector<int> Sblock = {S};
    vector<int> Zblock = {Z};
    vector<int> Tblock = {T};
    vector<int> restart = {RESTART};

    // adding the vectors to the map
    commands = {{fullCommand[LEFT], left}, {fullCommand[RIGHT], right}, {fullCommand[DOWN], down}, {fullCommand[CLOCKWISE], clockwise}, {fullCommand[COUNTERCLOCKWISE], counterclockwise}, {fullCommand[DROP], drop}, {fullCommand[LEVELUP], levelup}, {fullCommand[LEVELDOWN], leveldown}, {fullCommand[NORANDOM], norandom}, {fullCommand[RANDOM], random}, {fullCommand[SEQUENCE], sequence}, {fullCommand[I], Iblock}, {fullCommand[J], Jblock}, {fullCommand[L], L}, {fullCommand[O], O}, {fullCommand[S], S}, {fullCommand[Z], Z}, {fullCommand[T], T}, {fullCommand[RESTART], restart}};

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
        case LEFT:
            // left();
            break;
        case RIGHT:
            // right();
            break;
        case DOWN:
            // down();
            break;
        case CLOCKWISE:
            // clockwise();
            break;
        case COUNTERCLOCKWISE:
            // counterclockwise();
            break;
        case DROP:
            // drop();
            break;
        case LEVELUP:
            // levelup();
            break;
        case LEVELDOWN:
            // leveldown();
            break;
        case NORANDOM:
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
        case RANDOM:
            // random();
            break;
        case SEQUENCE:
            cin >> file;
            // sequence(file);
            break;
        case I:
            // I();
            break;
        case J:
            // J();
            break;
        case L:
            // L();
            break;
        case O:
            // O();
            break;
        case S:
            // S();
            break;
        case Z:
            // Z();
            break;
        case T:
            // T();
            break;
        case RESTART:
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
