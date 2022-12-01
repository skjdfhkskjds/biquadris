#include "effect.h"
#include "effectfactory.h"
#include "blindcreator.h"
#include "blindproduct.h"
#include <memory>

using namespace std;

unique_ptr<Effect> BlindCreator::createEffect()
{
    return make_unique<BlindProduct>();
}