#ifndef _FORCE_
#define _FORCE_

#include <memory>
#include "../effectdecorator.h"

class AbstractBoard;

class Force : public EffectDecorator
{
    char forcedBlock;

    void apply() override;

public:
    Force(std::unique_ptr<AbstractBoard> component, char forcedBlock);

    std::vector<char> getState() override;

    std::unique_ptr<Block> getBlock(char c) override;
    void setBlock(std::unique_ptr<Block> block) override;

    void right() override;
    void left() override;
    void down() override;

};

#endif
