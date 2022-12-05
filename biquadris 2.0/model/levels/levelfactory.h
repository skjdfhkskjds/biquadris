#ifndef _LEVELFACTORY_
#define _LEVELFACTORY_

#include "level.h"
#include <memory>

class LevelFactory
{
public:
    virtual ~LevelFactory() noexcept {}
    
    // method to return object of level class; subclasses will override this method to change resulting effect type
    virtual std::unique_ptr<Level> createLevel() = 0;

    // calls factory method to create an level object
    char levelOperation();
};

// how to call:
// std::unique_ptr<LevelFactory> factory = make_unique<Level0Creator>();
// factory.levelOperation();

#endif
