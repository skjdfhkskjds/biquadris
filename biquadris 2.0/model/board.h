#ifndef _BOARD_
#define _BOARD_

#include <memory>
#include <string>
#include "abstractboard.h"
#include "block.h"
#include "level.h"

class Board : public AbstractBoard
{
    class BoardImpl;
    std::unique_ptr<BoardImpl> impl;

public:
    Board(std::unique_ptr<Level> lvl, std::unique_ptr<Block> currBlock, std::unique_ptr<Block> nextBlock) noexcept;
    ~Board() noexcept;

    std::unique_ptr<Block> getBlock(char c) override;     // gets a new block based on level or c
    void setBlock(std::unique_ptr<Block> block) override; // sets current block to block

    std::vector<char> getState() override; // returns the boardState

    void counterClockwise(); // rotates the block counter clockwise
    void clockwise();        // rotates the block clockwise

    void right() override; // shifts the block right
    void left() override;  // shifts the block left
    void down() override;  // shifts the block down

    char getNext(); // returns the next block's char
};

#endif
