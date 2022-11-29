#include "leveldecorator.h"
#include "board.h"

LevelDecorator::LevelDecorator(Board *component)
    : component{component} {}

LevelDecorator::~LevelDecorator() {}