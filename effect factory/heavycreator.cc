#include "effect.h"
#include "effectfactory.h"
#include "heavycreator.h"
#include "heavyproduct.h"
#include <memory>

using namespace std;

unique_ptr<Effect> HeavyCreator::createEffect()
{
    return make_unique<HeavyProduct>();
}