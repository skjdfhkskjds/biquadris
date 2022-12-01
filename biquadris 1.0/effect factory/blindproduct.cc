#include "blindproduct.h"
#include "../boardstate.h"
#include "../coordinates.h"

using namespace std;

BoardState BlindProduct::runEffect(BoardState updatedBoard)
{
    vector<char> boardStateCopy = updatedBoard.boardState;
    for (int x = 3; x <= 9; x++) {
        for (int y = 3; y <= 12; y++) {
            int index = ((11 * y) + x);
            boardStateCopy[index] = '?';
        }
    }
    // how to return boardstate without permanent change
}
