#ifndef _FORCECREATOR_
#define _FORCECREATOR_

#include "effectfactory.h"
#include "effect.h"
#include <memory>

class ForceCreator : public EffectFactory
{
public:
    std::unique_ptr<Effect> createEffect() override;
};

#endif
