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

vector<char> Blind::getState()
{
    state = component->getState();
    apply();
    return ;
}

unique_ptr<Block> Blind::getBlock(char c)
{
    return component->getBlock(c);
}

void Blind::setBlock(unique_ptr<Block> block)
{
    component->setBlock(move(block));
}

void Blind::left()
{
    component->left();
}

void Blind::right()
{
    component->right();
}

void Blind::down()
{
    component->down();
}
