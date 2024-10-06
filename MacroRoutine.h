#ifndef MACRO_ROUTINE_H
#define MACRO_ROUTINE_H

#include "Command.h"
#include <vector>
#include <iostream>
using namespace std;

class MacroRoutine
{
    private:
    std::vector<Command*> routine;  
     
    public:
    ~MacroRoutine();
    void addProcedure(Command* command);
    void removeProcedure();
    void execute();
};

#endif 
