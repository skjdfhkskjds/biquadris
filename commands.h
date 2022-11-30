#ifndef _COMMANDS_
#define _COMMANDS_

#include <string>
#include <memory>

class Commands
{
protected:
    class CommandsImpl;
    std::unique_ptr<CommandsImpl> pImpl;

public:
    Commands() noexcept;
    ~Commands() noexcept;

    void interpret(std::string &command);
    void apply(std::string &command);
    bool rename(std::string &existing, std::string &newName);
    bool addMacro(std::string &command);
};

#endif
