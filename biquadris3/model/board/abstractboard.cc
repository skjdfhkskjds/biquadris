#include "abstractboard.h"

AbstractBoard::AbstractBoard(std::unique_ptr<AbstractBoard> component) : component{move(component)} {}

AbstractBoard::~AbstractBoard() {}
