#ifndef _BOARD_
#define _BOARD_

#include <memory>
#include <vector>
#include <string>

class Board
{
    class BoardImpl;
    std::unique_ptr<BoardImpl> impl;

public:
    Board() noexcept;
    ~Board() noexcept;

    std::vector<char> applyEffect(std::string effect); // applies the effect to current board
    std::vector<char> getState();                      // returns the boardState
};

#endif
