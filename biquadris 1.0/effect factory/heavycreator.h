#ifndef _HEAVYCREATOR_
#define _HEAVYCREATOR_

#include "effectfactory.h"
#include "effect.h"
#include <memory>

class HeavyCreator : public EffectFactory
{
public:
    std::unique_ptr<Effect> createEffect() override;
};

#endif
