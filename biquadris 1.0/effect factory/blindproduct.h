#ifndef _BLINDPRODUCT_
#define _BLINDPRODUCT_

#include "effect.h"
#include "../boardstate.h"

class BlindProduct : public Effect
{
public:
    BoardState runEffect() override;
};

#endif
