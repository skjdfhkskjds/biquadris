#include "level.h"

Level::Level(int seed, int lvlNum, std::vector<char> sequence) : seed{seed}, lvlNum{lvlNum}, sequence{sequence} {}

int Level::getLevel()
{
    return lvlNum;
}

