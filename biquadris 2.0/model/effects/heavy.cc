#include <memory>
#include "heavy.h"
#include "effectdecorator.h"

using namespace std;

Heavy::Heavy(unique_ptr<AbstractBoard> component, int weight = 0) : weight{weight}, EffectDecorator{move(component)} {}

void Heavy::apply()
{
    for (int i = 0; i < weight; i++)
    {
        component->down();
    }
}

vector<char> Heavy::getState()
{
    return component->getState();
}

unique_ptr<Block> Heavy::getBlock(char c)
{
    return component->getBlock(c);
}

void Heavy::setBlock(unique_ptr<Block> block)
{
    component->setBlock(move(block));
}

void Heavy::left()
{
    component->left();
    apply();
}

void Heavy::right()
{
    component->right();
    apply();
}

void Heavy::down()
{
    component->down();
}
