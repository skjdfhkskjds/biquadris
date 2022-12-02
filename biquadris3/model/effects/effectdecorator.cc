#include <memory>
#include "effectdecorator.h"

using namespace std;

EffectDecorator::EffectDecorator(unique_ptr<AbstractBoard> component) : AbstractBoard{move(component)} {}

EffectDecorator::~EffectDecorator() {}
