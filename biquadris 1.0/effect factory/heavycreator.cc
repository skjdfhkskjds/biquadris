#include "../boardstate.h"
#include "effect.h"
#include "effectfactory.h"
#include "heavycreator.h"
#include "heavyproduct.h"
#include <memory>

using namespace std;

bool HeavyCreator::longLastingEffect = true;

HeavyCreator::HeavyCreator(BoardState updatedBoard) : updatedBoard{updatedBoard} {}

unique_ptr<Effect> HeavyCreator::createEffect()
{
    return make_unique<HeavyProduct>();
}