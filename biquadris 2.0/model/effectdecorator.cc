#include <memory>
#include "effectdecorator.h"

using namespace std;

EffectDecorator::EffectDecorator(unique_ptr<AbstractBoard> component) : component{move(component)} {}

EffectDecorator::~EffectDecorator() {}
