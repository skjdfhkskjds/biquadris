#ifndef _TEXT_
#define _TEXT_

#include <memory>
#include "observer.h"
#include "board.h"

class TextView : public Observer
{
    std::shared_ptr<Board> board;
public:
    TextView(std::shared_ptr<Board> board);
    ~TextView();
    void notify() override;
    void draw() override;
};

#endif
