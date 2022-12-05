#include <memory>
#include "force.h"
#include "effectdecorator.h"

using namespace std;

Force::Force(unique_ptr<AbstractBoard> component, char forcedBlock) : forcedBlock{forcedBlock}, EffectDecorator{move(component)} {}

void Force::apply()
{
    shared_ptr<Block> block = component->makeBlock(forcedBlock);
    component->setBlock(block);
}

char Force::getNext() { return component->getNext(); }

vector<char> Force::getState() { return component->getState(); }

shared_ptr<Block> Force::makeBlock(char c) { return component->makeBlock(c); }

void Force::setBlock(shared_ptr<Block> &block) { component->setBlock(block); }

void Force::setLevel(int level) { component->setLevel(level); }

void Force::left() { component->left(); }

void Force::right() { component->right(); }

void Force::down() { component->down(); }
