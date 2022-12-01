#include "effect.h"
#include "effectfactory.h"
#include "forcecreator.h"
#include "forceproduct.h"
#include <memory>

using namespace std;

unique_ptr<Effect> ForceCreator::createEffect()
{
    return make_unique<ForceProduct>();
}