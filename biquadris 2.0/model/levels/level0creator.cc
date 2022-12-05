#include "level.h"
#include "levelfactory.h"
#include "level0creator.h"
#include "level0product.h"
#include <memory>

using namespace std;

unique_ptr<Level> LevelZeroCreator::createLevel()
{
    return make_unique<LevelZeroProduct>(sequence);
}