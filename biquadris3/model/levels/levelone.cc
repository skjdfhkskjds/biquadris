#include "levelone.h"
#include "../../common/random.h"

#define toUpper(c) (char)(('a' <= c && c <= 'z') ? (c - 'a' + 'A') : c)

LevelOne::LevelOne(int seed) : Level{seed, seed} , i{1}, randNum{Random{seed}} {}

void LevelOne::setRandom(bool newValue) {}

char LevelOne::generateBlock()
{
    int random = randNum.getRand(12);
    if (random == 0)
    {
        return 'S';
    }
    else if (random == 1)
    {
        return 'Z';
    }
    else if (random == 2 || random == 3)
    {
        return 'I';
    }
    else if (random == 4 || random == 5)
    {
        return 'J';
    }
    else if (random == 6 || random == 7)
    {
        return 'L';
    }
    else if (random == 8 || random == 9)
    {
        return 'O';
    }
    else
    {
        return 'T';
    }
    i++;
}