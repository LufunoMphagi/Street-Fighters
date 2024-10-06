#ifndef ALARM_H
#define ALARM_H

#include "Observer.h"
#include <iostream>
using namespace std;

class Alarm : public Observer
{
    public:
    void update() override;
};

#endif 