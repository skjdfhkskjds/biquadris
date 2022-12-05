#include "level0product.h"
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
#include <vector>

using namespace std;

LevelZeroProduct::LevelZeroProduct(vector<char> sequence) : sequence{sequence} {}

LevelZeroProduct::~LevelZeroProduct() {}

void LevelZeroProduct::popFront()
{
    if (sequence.size() > 0)
    {
        sequence.erase(sequence.begin());
    }
}

char LevelZero::blockGenerator()
{
    char temp = sequence.front();
    popFront();
    return temp;
};
