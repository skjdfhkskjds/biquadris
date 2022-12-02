#ifndef _GRAPHICS_
#define _GRAPHICS_

#include <memory>
#include <vector>
#include "observer.h"
#include "../model/player.h"
#include <map>

class Graphics : public Observer
{
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::vector<char>> oldStates;
    std::vector<std::vector<char>> newStates;
    std::map<int,char> getDeltas(int p);
public:
    Graphics(std::vector<std::shared_ptr<Player>> players);
    ~Graphics();
    void notify() override;
};
#endif