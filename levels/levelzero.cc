#include "levelzero.h"
#include "../board.h"
#include "../blocks/iblock.h"
#include "../blocks/jblock.h"
#include "../blocks/lblock.h"
#include "../blocks/oblock.h"
#include "../blocks/sblock.h"
#include "../blocks/tblock.h"
#include "../blocks/zblock.h"
#include <cstdlib>
#include <string>

using namespace std;

LevelZero::LevelZero(vector<char> sequence) : sequence{sequence} {}

LevelZero::~LevelZero() {}

void LevelZero::popFront()
{
    if (sequence.size() > 0)
    {
        sequence.erase(sequence.begin());
    }
}

unique_ptr<Block> LevelZero::blockGenerator()
{
    char temp = sequence.front();
    popFront();
    if (temp == 'S')
    {
        return make_unique<SBlock>();
    }
    else if (temp == 'Z')
    {
        return make_unique<ZBlock>();
    }
    else if (temp == 'I')
    {
        return make_unique<IBlock>();
    }
    else if (temp == 'J')
    {
        return make_unique<JBlock>();
    }
    else if (temp == 'L')
    {
        return make_unique<LBlock>();
    }
    else if (temp == 'O')
    {
        return make_unique<OBlock>();
    }
    else
    {
        return make_unique<TBlock>();
    }
};
