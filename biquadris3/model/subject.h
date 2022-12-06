#ifndef _SUBJECT_
#define _SUBJECT_

#include <vector>
#include <memory>
#include "../viewer/observer.h"

class Observer;

class Subject
{
    std::vector<std::unique_ptr<Observer>> observers;

public:
    virtual ~Subject() = default;

    void attach(std::unique_ptr<Observer> o);
    void detach(std::unique_ptr<Observer> o);
    void notifyObservers();
    
    virtual std::vector<std::vector<char>> getState() = 0;
};

#endif
