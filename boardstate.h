#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <vector>
#include "board.h"

class BoardState
{
    const int width = 11;
    const int height = 18;
    std::vector<char> boardState;
public:
    BoardState();
    void clearRow(int row);
    bool checkRow(int row);
};

#endif
