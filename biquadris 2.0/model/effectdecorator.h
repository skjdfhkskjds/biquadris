#ifndef _EFFECTECORATOR_
#define _EFFECTDECORATOR_

#include <memory>
#include "abstractboard.h"

class EffectDecorator : public AbstractBoard
{
protected:
    std::unique_ptr<AbstractBoard> component;

    virtual void apply();

public:
    EffectDecorator(std::unique_ptr<AbstractBoard> component);
    virtual ~EffectDecorator();
};

#endif
