#ifndef _FORCE_
#define _FORCE_

#include <memory>
#include "effectdecorator.h"

class AbstractBoard;

class Force : public EffectDecorator
{
    char forcedBlock;

    void apply() override; // applies the force effect

public:
    Force(std::unique_ptr<AbstractBoard> component, char forcedBlock);

    char getNext() override;
    std::vector<char> getState() override;

    std::unique_ptr<Block> makeBlock(char c) override;
    void setBlock(std::unique_ptr<Block> block) override;

    void clockwise() override;
    void counterClockwise() override;
    void right() override;
    void left() override;
    void down() override;

};

#endif
