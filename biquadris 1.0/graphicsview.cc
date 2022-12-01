#include <memory>
#include "graphicsview.h"

using namespace std;

GraphicsView::GraphicsView(std::shared_ptr<Board> board) : board{board}, window{new XWindow{}} {}

int GraphicsView::getColour(char c)
{
    // fill in case switch for which colours we want
}

void GraphicsView::notify()
{

}

void GraphicsView::draw()
{

}
