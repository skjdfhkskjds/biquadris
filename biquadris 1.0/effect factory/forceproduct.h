#ifndef _FORCEPRODUCT_
#define _FORCEPRODUCT_

#include "effect.h"
#include "../boardstate.h"

class ForceProduct : public Effect
{
public:
    BoardState runEffect() override;
};

#endif
