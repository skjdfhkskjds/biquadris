#ifndef _LEVEL0_
#define _LEVEL0_

#include <vector>
#include "../block.h"
#include "../Level.h"

class LevelZero : public Level
{
    // in main, read in alternating characters from sequence1.txt and sequence2.txt
    // if the game has not ended at file eof, read from file again

    std::vector<char> sequence;
    void popFront();

public:
    LevelZero(std::vector<char> sequence) noexcept;
    ~LevelZero() noexcept;
    std::unique_ptr<Block> blockGenerator() override;
};

#endif
