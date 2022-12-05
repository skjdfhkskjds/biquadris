#include "levelfactory.h"
#include <memory>

using namespace std;

char LevelFactory::levelOperation()
{
    unique_ptr<Level> level = this->createLevel();
    char newBlock = level->blockGenerator();
}