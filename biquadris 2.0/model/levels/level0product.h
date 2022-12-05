#ifndef _LEVEL0PRODUCT_
#define _LEVEL0PRODUCT_

#include "level.h"

class LevelZeroProduct : public Level
{
    int seed;
    int lvlNum;
    std::vector<char> sequence;

public:
    LevelZeroProduct(std::vector<char> sequence) noexcept;
    ~LevelZeroProduct() noexcept;
    void popFront();
    char blockGenerator() override;
};

#endif
