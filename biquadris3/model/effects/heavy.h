#ifndef _HEAVY_
#define _HEAVY_

#include <memory>
#include "effectdecorator.h"

class AbstractBoard;

class Heavy : public EffectDecorator
{
    int weight;

    void apply() override; // applies the heavy effect on left() and right()

public:
    Heavy(std::unique_ptr<AbstractBoard> component, int weight=0);

    char getNext() override;
    std::vector<char> getState() override;

    std::shared_ptr<Block> makeBlock(char c) override;
    void setBlock(std::shared_ptr<Block> &block) override;
    void setLevel(int level) override;

    void clockwise() override;
    void counterClockwise() override;
    void right() override;
    void left() override;
    void down() override;
};

#endif
