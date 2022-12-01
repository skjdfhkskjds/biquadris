#include "../boardstate.h"
#include "effect.h"
#include "effectfactory.h"
#include "forcecreator.h"
#include "forceproduct.h"
#include <memory>

using namespace std;

bool ForceCreator::longLastingEffect = true;

ForceCreator::ForceCreator(BoardState updatedBoard) : updatedBoard{updatedBoard} {}

unique_ptr<Effect> ForceCreator::createEffect()
{
    return make_unique<ForceProduct>();
}