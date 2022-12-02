#include "level.h"

Level::Level(int seed, int lvl) : seed{seed}, lvl{lvl} {}

int Level::getLvl() { return lvl; }
