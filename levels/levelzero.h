#ifndef _LEVEL0_
#define _LEVEL0_

#include <vector>
#include "../block.h"
#include "../leveldecorator.h"

class LevelZero : public LevelDecorator
{
    // in main, read in alternating characters from sequence1.txt and sequence2.txt
    // if the game has not ended at file eof, read from file again
    std::vector<char> sequence;
    void popFront();

public:
        std::unique_ptr<Block> blockGenerator() override;
};

#endif
