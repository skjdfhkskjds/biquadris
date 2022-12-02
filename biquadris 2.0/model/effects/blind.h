#ifndef _BLIND_
#define _BLIND_

#include <memory>
#include <vector>
#include "../effectdecorator.h"

class AbstractBoard;

class Blind : public EffectDecorator
{
    std::vector<char> state;

    void apply() override;

public:
    Blind(std::unique_ptr<AbstractBoard> component);

    std::vector<char> getState() override;

    std::unique_ptr<Block> getBlock(char c) override;
    void setBlock(std::unique_ptr<Block> block) override;

    void right() override;
    void left() override;
    void down() override;

};

#endif
