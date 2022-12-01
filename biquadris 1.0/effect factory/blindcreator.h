#ifndef _BLINDCREATOR_
#define _BLINDCREATOR_

#include "effectfactory.h"
#include "effect.h"
#include <memory>

class BlindCreator : public EffectFactory
{
public:
    std::unique_ptr<Effect> createEffect() override;
};

#endif
