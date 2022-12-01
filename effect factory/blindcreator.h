#ifndef _BLINDCREATOR_
#define _BLINDCREATOR_

#include <memory>
#include "../boardstate.h"
#include "effectfactory.h"
#include "effect.h"

class BlindCreator : public EffectFactory
{
    static bool longLastingEffect;
    BoardState updatedBoard;
public:
    BlindCreator(BoardState updatedBoard) noexcept;
    std::unique_ptr<Effect> createEffect() override;
};

#endif
