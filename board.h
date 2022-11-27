#ifndef _BOARD_
#define _BOARD_

#include <memory>
#include "subject.h"
#include "block.h"

class Board : public Subject
{
    class BoardImpl;
    std::unique_ptr<BoardImpl> pImpl;
public:
    Board() noexcept;
    ~Board() noexcept;

    void getState();
    void addBlock(Block &block);
};

#endif
