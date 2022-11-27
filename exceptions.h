#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#include <exception>
#include <string>

using namespace std;

// EXCEPTIONS CLASS : ADD TO IT AS NEEDED

class command_not_found : public exception
{
    string command;
public:
    command_not_found(string &command);
    string what();
};

class command_already_exists : public exception
{
    string command;
public:
    command_already_exists(string &command);
    string what();
};

#endif
