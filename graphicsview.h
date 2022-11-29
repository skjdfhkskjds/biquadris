#ifndef _GRAPHICS_
#define _GRAPHICS_

#include <memory>
#include "observer.h"
#include "board.h"
#include "xwindow.h"

class GraphicsView : public Observer
{
    // set dimensions
    const int width = 0;
    const int height = 0;

    std::unique_ptr<XWindow> window;
    std::shared_ptr<Board> board;
    int getColour(char c);
public:
    GraphicsView(std::shared_ptr<Board> board);
    ~GraphicsView();
    void notify() override;
    void draw() override;
};

#endif
