#ifndef _EFFECTFACTORY_
#define _EFFECTFACTORY_

#include "../boardstate.h"
#include "effect.h"
#include <memory>


class EffectFactory
{
protected:
    BoardState updatedBoard;
    bool longLastingEffect;

public:
    virtual ~EffectFactory() noexcept {}
    BoardState getState();
    bool isLongLasting();
    // method to return object of effect class; subclasses will override this method to change resulting effect type
    virtual std::unique_ptr<Effect> createEffect() = 0;
    // calls factory method to create an effect object
    void effectOperation();
};

#endif
