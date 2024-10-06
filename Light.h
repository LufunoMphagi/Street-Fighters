#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include <iostream>
using namespace std;

class Light : public SmartDevice
{
    private:
    bool isOn;

    public:
    Light();
    virtual ~Light() {}

    void toggleOn() override;
    void toggleOff() override;
    void toggle() override;

    string getStatus() const override;
    void performAction(const string& action) override;
    string getDeviceType() const override;
};

#endif
