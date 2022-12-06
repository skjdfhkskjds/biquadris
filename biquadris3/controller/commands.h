#ifndef _COMMANDS_
#define _COMMANDS_

#include <string>
#include <memory>
#include "game.h"
#include "../model/player.h"

class Commands final
{
    class CommandsImpl;
    std::unique_ptr<CommandsImpl> impl;
    std::unique_ptr<Game> game;

public:
    Commands() noexcept;
    ~Commands() noexcept;

    std::vector<std::string> interpret(std::string &command); // interprets a string input and applies commands appropriately
    int getPlayerCommand(std::string &command);               // returns the player command
    void apply(std::string &command);                         // applies the interpreted input

    bool rename(std::string &existing, std::string &newName); // renames a command
    bool addMacro(std::string &command);                      // adds a macro
    std::string stringInterpret(std::string &command);
};

#endif
