#ifndef _EFFECTECORATOR_
#define _EFFECTDECORATOR_

#include <memory>
#include "../board/abstractboard.h"

class EffectDecorator : public AbstractBoard
{
protected:
    virtual void apply();

public:
    EffectDecorator(std::unique_ptr<AbstractBoard> component);
    virtual ~EffectDecorator();
};

#endif
