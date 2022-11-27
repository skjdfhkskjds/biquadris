#ifndef _BOARDSTATE_
#define _BOARDSTATE_

#include <vector>

class BoardState
{
    std::vector<char> boardState;
public:
    BoardState();
    void clearRow();
    bool checkRow();
};

#endif
