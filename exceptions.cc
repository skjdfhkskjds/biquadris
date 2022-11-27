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
