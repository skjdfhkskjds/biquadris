#include "exceptions.h"
#include <string>

using namespace std;

// command_not_found implementation
command_not_found::command_not_found(string &command) : command{command} {}

string command_not_found::what()
{
    return command + " is not a valid command.";
}

// command_already_exists implementation
command_already_exists::command_already_exists(string &command) : command{command} {}

string command_already_exists::what()
{
    return command + " is already an existing command.";
}

//file_not_found implementation

string file_not_found::sequence1 = "sequence1.txt";
string file_not_found::sequence2 = "sequence2.txt";

file_not_found::file_not_found(string &file) : file{file} {}

string file_not_found::what()
{
    return file + " does not exist.";
}

string file_not_found::getDefault(int type)
{
    return (type == 1) ? sequence1 : sequence2;
}

string invalid_move::what()
{
    return "Invalid move";
}