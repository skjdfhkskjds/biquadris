#ifndef _COMMANDS_
#define _COMMANDS_

#include <string>
#include <memory>

class Commands final
{
    class CommandsImpl;
    std::unique_ptr<CommandsImpl> impl;

public:
    Commands() noexcept;
    ~Commands() noexcept;

    void interpret(std::string &command); // interprets a string input and applies commands appropriately
    void apply(std::string &command);     // applies the interpreted input

    bool rename(std::string &existing, std::string &newName); // renames a command
    bool addMacro(std::string &command);                      // adds a macro
};

#endif
