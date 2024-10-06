#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include "Command.h"
using namespace std;
#include <iostream>

class LockAllDoors : public Command
{
    public:
    void execute() override;
};

#endif