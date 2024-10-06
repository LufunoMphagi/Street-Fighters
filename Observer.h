#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class Observer
{
    public:
    virtual ~Observer() {}
    virtual void update() = 0; 
};

#endif 