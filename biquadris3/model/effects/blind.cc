#include <memory>
#include "blind.h"
#include "effectdecorator.h"

#define width 11
#define height 18

using namespace std;

Blind::Blind(unique_ptr<AbstractBoard> component) : EffectDecorator{move(component)} {}

void Blind::apply()
{
    for (int y = 3; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x >= 3 && x <= 9 && y >= 3 && y <= 12)
            {
                state[y * width + x] = '?';
            }
        }
    }
}

char Blind::getNext() { return component->getNext(); }

vector<char> Blind::getState()
{
    state = component->getState();
    apply();
    return ;
}

shared_ptr<Block> Blind::makeBlock(char c) { return component->makeBlock(c); }

void Blind::setBlock(shared_ptr<Block> &block) { component->setBlock(block); }

void Blind::setLevel(int level) { component->setLevel(level); }

void Blind::setup() { component->setup(); }

void Blind::left() { component->left(); }

void Blind::right() { component->right(); }

void Blind::down() { component->down(); }

void Blind::drop() { component->drop(); }
