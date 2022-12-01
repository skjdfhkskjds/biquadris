#ifndef _SUBJECT_
#define _SUBJECT_

#include <vector>
#include "observer.h"

class Observer;

class Subject
{
    std::vector<Observer *> observers;

public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual ~Subject() = default;
};

#endif
