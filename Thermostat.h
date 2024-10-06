#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"
#include <iostream>
using namespace std;

class Thermostat : public SmartDevice
{
    private:
    double temperature;
    bool isOn;

    public:
    Thermostat();
    virtual ~Thermostat() {}

    void toggleOn() override;
    void toggleOff() override;
    void toggle() override;

    string getStatus() const override;
    void performAction(const string& action) override;
    string getDeviceType() const override;

    void setTemperature(double temp);
    double getTemperature() const;
};

#endif 
