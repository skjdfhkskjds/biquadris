#ifndef _ABSBOARD_
#define _ABSBOARD_

#include <memory>
#include <string>
#include "block.h"

class AbstractBoard
{

public:
    AbstractBoard() noexcept;
    ~AbstractBoard() noexcept;

    virtual std::vector<char> getState();
    
    virtual std::unique_ptr<Block> getBlock(char c) = 0;
    virtual void setBlock(std::unique_ptr<Block> block) = 0;

    virtual void right() = 0;
    virtual void left() = 0;
    virtual void down() = 0;

};

#endif
