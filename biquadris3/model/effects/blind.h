#ifndef _BLIND_
#define _BLIND_

#include <memory>
#include <vector>
#include "effectdecorator.h"

class AbstractBoard;

class Blind : public EffectDecorator
{
    std::vector<char> state;

    void apply() override; // applies the blind effect to getState()

public:
    Blind(std::unique_ptr<AbstractBoard> component);

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
    void drop() override;

};

#endif
