#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"
#include <iostream>
using namespace std;

class DoorLock : public SmartDevice
{
    private:
    bool isLocked;

    public:
    DoorLock();
    virtual ~DoorLock() {}

    void toggleOn() override;    
    void toggleOff() override;   
    void toggle() override;      

    string getStatus() const override;
    void performAction(const string& action) override;
    string getDeviceType() const override;

    void lock();
    void unlock();
};

#endif 
