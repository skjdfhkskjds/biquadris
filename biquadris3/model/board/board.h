#ifndef _BOARD_
#define _BOARD_

#include <memory>
#include <string>
#include "abstractboard.h"
#include "../blocks/block.h"

class Board : public AbstractBoard
{
    class BoardImpl;
    std::unique_ptr<BoardImpl> impl;

public:
    Board(int startLvl) noexcept;
    ~Board() noexcept;

    std::unique_ptr<Block> makeBlock(char c) override;    // makes a new block based on level or c
    void setBlock(std::unique_ptr<Block> block) override; // sets current block to block

    // getter methods
    std::vector<char> getState() override; // returns the boardState
    char getNext() override;               // returns the next block's char

    void counterClockwise() override; // rotates the block counter clockwise
    void clockwise() override;        // rotates the block clockwise
    void right() override;            // shifts the block right
    void left() override;             // shifts the block left
    void down() override;             // shifts the block down
};

#endif
