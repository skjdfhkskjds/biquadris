#include "../boardstate.h"
#include "effect.h"
#include "effectfactory.h"
#include <memory>

using namespace std;

BoardState EffectFactory::getState()
{
}
bool EffectFactory::isLongLasting()
{
}

void EffectFactory::effectOperation()
{
    unique_ptr<Effect> effect = this->createEffect();
    effect->runEffect(updatedBoard);
}