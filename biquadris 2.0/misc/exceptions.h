#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#include <exception>
#include <string>

// EXCEPTIONS CLASS : ADD TO IT AS NEEDED

class command_not_found : public exception
{
    std::string command;

public:
    command_not_found(std::string &command);
    std::string what();
};

class command_already_exists : public exception
{
    std::string command;

public:
    command_already_exists(std::string &command);
    std::string what();
};

class file_not_found : public exception
{
    static std::string sequence1;
    static std::string sequence2;
    std::string file;

public:
    file_not_found(std::string &command);
    std::string what();
    std::string getDefault(int type); // returns the default file for sequence 'type'
};

class invalid_move : public exception
{

public:
    invalid_move();
    std::string what();
};

#endif
