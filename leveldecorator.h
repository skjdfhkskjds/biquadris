#ifndef _LEVELDECORATOR_
#define _LEVELDECORATOR_

#include "board.h"
#include "block.h"
#include <memory>

class LevelDecorator : public Board
{
protected:
    std::unique_ptr<Board> component;

public:
    LevelDecorator( std::unique_ptr<Board> component );
    virtual ~LevelDecorator() = default;
    virtual std::unique_ptr<Block> blockGenerator() = 0;
};

#endif
