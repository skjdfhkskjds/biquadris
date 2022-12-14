#ifndef _OBSERVER_
#define _OBSERVER_

class Subject;

class Observer
{
public:
    virtual void notify() = 0;
    virtual ~Observer() = default;
    virtual void draw() = 0;
};
#endif
