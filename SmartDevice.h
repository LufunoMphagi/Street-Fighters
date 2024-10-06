#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
using namespace std;

// Abstract Base Class for Smart Devices
class SmartDevice
{
    public:
    virtual ~SmartDevice() {}

    virtual void toggleOn() = 0;
    virtual void toggleOff() = 0;
    virtual void toggle() = 0;

    virtual string getStatus() const = 0;
    virtual void performAction(const string& action) = 0;
    virtual string getDeviceType() const = 0;
};

#endif 
