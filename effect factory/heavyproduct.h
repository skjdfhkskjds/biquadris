#ifndef _HEAVYPRODUCT_
#define _HEAVYPRODUCT_

#include "effect.h"
#include "../boardstate.h"

class HeavyProduct : public Effect
{
public:
    BoardState runEffect() override;
};

#endif
