#ifndef _GRAPHICS_
#define _GRAPHICS_

#include <memory>
#include <vector>
#include "observer.h"
#include "window.h"
#include "../model/player.h"
#include <map>

class Graphics : public Observer
{
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::vector<char>> oldStates;
    std::vector<std::vector<char>> newStates;
    std::map<int,char> getDeltas(int p);
    Xwindow xWindow;
public:
    Graphics(std::vector<std::shared_ptr<Player>> players, Xwindow xWindow);
    ~Graphics();
    void notify() override;
};
#endif