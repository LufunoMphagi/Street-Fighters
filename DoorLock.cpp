#include "DoorLock.h"

DoorLock::DoorLock()
{
    isLocked = false;
}

void DoorLock::toggleOn()
{
    lock();
}

void DoorLock::toggleOff()
{
    unlock();
}


void DoorLock::toggle()
{
    if(isLocked)
    {
        unlock();
    }
    else
    {
        lock();
    }
}

string DoorLock::getStatus() const
{
    return isLocked ? "locked" : "unlocked";
}

void DoorLock::performAction(const string& action)
{
    if(action == "ToggleOn")
    {
        lock();
    }

    else if(action == "ToggleOff")
    {
        unlock();
    }

    else if(action == "Toggle")
    {
        toggle();
    }

    else
    {
        cout << "Invalid action for DoorLock." << endl;
    }
}

string DoorLock::getDeviceType() const
{
    return "DoorLock";
}

void DoorLock::lock()
{
    isLocked = true;
    cout << "Door locked." << endl;
}

void DoorLock::unlock()
{
    isLocked = false;
    cout << "Door unlocked." << endl;
}
