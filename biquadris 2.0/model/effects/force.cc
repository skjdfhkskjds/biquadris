#include <memory>
#include "force.h"
#include "effectdecorator.h"

using namespace std;

Force::Force(unique_ptr<AbstractBoard> component, char forcedBlock) : forcedBlock{forcedBlock}, EffectDecorator{move(component)} {}

void Force::apply()
{
    unique_ptr<Block> block = move(component->getBlock(forcedBlock));
    component->setBlock(move(block));
}

vector<char> Force::getState()
{
    return component->getState();
}

unique_ptr<Block> Force::getBlock(char c)
{
    return component->getBlock(c);
}

void Force::setBlock(unique_ptr<Block> block)
{
    component->setBlock(move(block));
}

void Force::left()
{
    component->left();
}

void Force::right()
{
    component->right();
}

void Force::down()
{
    component->down();
}