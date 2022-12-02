#ifndef _HEAVY_
#define _HEAVY_

#include <memory>
#include "../effectdecorator.h"

class AbstractBoard;

class Heavy : public EffectDecorator
{
    int weight;

    void apply() override;

public:
    Heavy(std::unique_ptr<AbstractBoard> component, int weight=0);

    std::vector<char> getState() override;

    std::unique_ptr<Block> getBlock(char c) override;
    void setBlock(std::unique_ptr<Block> block) override;

    void right() override;
    void left() override;
    void down() override;
};

#endif
