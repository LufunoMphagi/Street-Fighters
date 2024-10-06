#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

class Command
{
    public:
    virtual ~Command() {}
    virtual void execute() = 0; 
};


#endif 
