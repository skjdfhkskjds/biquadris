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

char Heavy::getNext() { return component->getNext(); }

vector<char> Heavy::getState()
{
    return component->getState();
}

shared_ptr<Block> Heavy::makeBlock(char c)
{
    return component->makeBlock(c);
}

void Heavy::setBlock(shared_ptr<Block> &block)
{
    component->setBlock(block);
}

void Heavy::clockwise()
{
    component->clockwise();
}

void Heavy::counterClockwise()
{
    component->counterClockwise();
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
