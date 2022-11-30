#include "leveldecorator.h"
#include "board.h"
#include <utility>

using namespace std;

LevelDecorator::LevelDecorator(unique_ptr<Board> component)
    : component{move(component)} {}

LevelDecorator::~LevelDecorator() {}
