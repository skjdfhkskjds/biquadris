#include <memory>
#include "heavy.h"
#include "../../common/exceptions.h"
#include "../board/abstractboard.h"

using namespace std;

Heavy::Heavy(unique_ptr<AbstractBoard> component, int weight) : EffectDecorator{move(component)}, weight{weight} {}

Heavy::~Heavy() {}

void Heavy::apply()
{
    // apply down weight number of times
    for (int i = 0; i < weight; i++)
    {
        try
        {
            component->down();
        }
        catch(invalid_move& e)
        {
            continue;
        }
    }
}

char Heavy::getNext() { return component->getNext(); }

vector<char> Heavy::getState() { return component->getState(); }

shared_ptr<Block> Heavy::makeBlock(char c) { return component->makeBlock(c); }

void Heavy::setBlock(shared_ptr<Block> &block) { component->setBlock(block); }

void Heavy::setLevel(int level) { component->setLevel(level); }

void Heavy::setRandom(bool isRandom) { component->setRandom(isRandom); }

void Heavy::setSequence(vector<char> sequence) { component->setSequence(sequence); }

void Heavy::setup() { component->setup(); }

void Heavy::clockwise() { component->clockwise(); }

void Heavy::counterClockwise() { component->counterClockwise(); }

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

void Heavy::down() { component->down(); }

void Heavy::drop() { component->drop(); }
