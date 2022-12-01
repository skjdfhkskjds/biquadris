#include "levelthree.h"
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
// note: all blocks in level three are "heavy"
unique_ptr<Block> LevelThree::blockGenerator()
{
    srand((unsigned)time(NULL));
    int random = rand() % 9;
    if (random == 0 || random == 1)
    {
        return make_unique<SBlock>();
    }
    else if (random == 2 || random == 3)
    {
        return make_unique<ZBlock>();
    }
    else if (random == 4)
    {
        return make_unique<IBlock>();
    }
    else if (random == 5)
    {
        return make_unique<JBlock>();
    }
    else if (random == 6)
    {
        return make_unique<LBlock>();
    }
    else if (random == 7)
    {
        return make_unique<OBlock>();
    }
    else
    {
        return make_unique<TBlock>();
    }
};