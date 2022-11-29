#ifndef _LEVELDECORATOR_
#define _LEVELDECORATOR_

#include "board.h"
#include <memory>

class LevelDecorator : public Board
{
protected:
    std::unique_ptr<Board> component;

public:
    LevelDecorator( std::unique_ptr<Board> component );
    virtual ~LevelDecorator() = default;
    virtual Block blockGenerator() = 0;
};

#endif
