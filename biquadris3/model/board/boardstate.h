#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <vector>
#include <memory>
#include "../blocks/block.h"
#include "../../common/coordinates.h"
#include "../../common/square.h"

class BoardState
{
    int lvl;
    std::vector<Square> state;

    void clearSquare(Coordinates &c);        // clears the square at c
    void swap(Square &target, Square &dest); // swaps target and dest squares
    void move(Square &target, Square &dest); // moves target to dest

    void apply(std::shared_ptr<Block> &block, std::vector<std::vector<int>> transform); // applies transform to block

    bool isSafe(std::shared_ptr<Block> &block, std::vector<std::vector<int>> transform); // checks if a transformation is safe
    int rowScore(std::vector<std::shared_ptr<Block>> cleared);                         // returns the score of clearing the caller

public:
    BoardState(int lvl);

    // getter functions
    std::vector<char> getState(); // returns the state

    // row functions
    bool checkRow(int row); // returns whether row is filled
    int clearRow(int row);  // clears all squares on row and returns the score for clearing the row

    // setter functions
    void initBlock(std::shared_ptr<Block> block); // initializes the block to the boardstate

    // block transformations (update the square's block + update block coords)
    void clockwise(std::shared_ptr<Block> &block);
    void counterClockwise(std::shared_ptr<Block> &block);
    void left(std::shared_ptr<Block> &block);
    void right(std::shared_ptr<Block> &block);
    void down(std::shared_ptr<Block> &block);
};

#endif
