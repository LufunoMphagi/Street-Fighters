#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H

#include <iostream>
#include "Command.h"
using namespace std;

class TurnOffAllLights : public Command
{
    public:
    void execute() override;
};

#endif