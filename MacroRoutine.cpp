#include "MacroRoutine.h"

MacroRoutine::~MacroRoutine()
{
    for(Command *commandCount : routine)
    {
        delete commandCount;
    }
}


void MacroRoutine::addProcedure(Command *myCommand)
{
    routine.push_back(myCommand);
}

void MacroRoutine::removeProcedure()
{
    if(!routine.empty())
    {
        Command *myCommand = routine.back();
        routine.pop_back();
        delete myCommand;
    }
}

void MacroRoutine::execute()
{
    cout << "Executing Macro Routine:" << endl;
    for(Command *commandCount : routine)
    {
        commandCount->execute();
    }
}