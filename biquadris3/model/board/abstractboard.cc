#include "abstractboard.h"

AbstractBoard::AbstractBoard(std::unique_ptr<AbstractBoard> component=nullptr) : component{move(component)} {}

AbstractBoard::~AbstractBoard() {}
