#include "effect.h"
#include "effectfactory.h"
#include "blindcreator.h"
#include "blindproduct.h"
#include <memory>

using namespace std;

bool BlindCreator::longLastingEffect = false;

BlindCreator::BlindCreator(BoardState updatedBoard) : updatedBoard{updatedBoard} {}

unique_ptr<Effect> BlindCreator::createEffect()
{
    return make_unique<BlindProduct>();
}
