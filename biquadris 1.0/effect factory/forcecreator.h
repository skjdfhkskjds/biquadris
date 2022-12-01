#ifndef _FORCECREATOR_
#define _FORCECREATOR_

#include <memory>
#include "../boardstate.h"
#include "effectfactory.h"
#include "effect.h"

class ForceCreator : public EffectFactory
{
    static bool longLastingEffect;
    BoardState updatedBoard;

public:
    ForceCreator(BoardState updatedBoard) noexcept;
    std::unique_ptr<Effect> createEffect() override;
};

#endif
