#ifndef _HEAVYCREATOR_
#define _HEAVYCREATOR_

#include "../boardstate.h"
#include "effectfactory.h"
#include "effect.h"
#include <memory>

class HeavyCreator : public EffectFactory
{
    static bool longLastingEffect;
    BoardState updatedBoard;
public:
    HeavyCreator(BoardState updatedBoard) noexcept;
    std::unique_ptr<Effect> createEffect() override;
};

#endif
