#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <memory>
#include <vector>
#include "board.h"

class BoardState
{
    const int width = 11;
    const int height = 18;
    
public:
    std::vector<char> boardState;
    BoardState();
    void clearRow(int row) noexcept;
    bool checkRow(Coordinates &row) noexcept;
    bool isSafe(std::unique_ptr<Coordinates> dest);

};

#endif
