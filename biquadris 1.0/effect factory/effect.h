#ifndef _EFFECT_
#define _EFFECT_

#include "../boardstate.h"

// effect class declares the implementations of effect products (runEffect will nodify the BoardState)
class Effect
{
public:
    virtual ~Effect() noexcept {}
    virtual BoardState runEffect(BoardState updatedBoard) = 0;
};

#endif
