#ifndef _TEXT_
#define _TEXT_

#include <memory>
#include <vector>
#include "observer.h"
#include "../model/player.h"

class Text : public Observer
{
    std::vector<std::shared_ptr<Player>> players;
public:
    Text(std::vector<std::shared_ptr<Player>> players);
    ~Text();
    void notify() override;
};

#endif