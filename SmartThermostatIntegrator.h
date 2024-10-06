#ifndef SMART_THERMOSTAT_INTEGRATOR_H
#define SMART_THERMOSTAT_INTEGRATOR_H

#include <string>
using namespace std;

class OldThermostat
{
    private:
    int currentTemperature;  

    public:
    OldThermostat();
    void setLegacyTemperature(int temp);
    int getLegacyTemperature();
};


class SmartThermostatIntegrator
{
    private:
    OldThermostat* legacyThermostat;
    
    public:
    SmartThermostatIntegrator();
    SmartThermostatIntegrator(OldThermostat* oldThermostat);
    
    void setTemperature(int temp); 
    int getTemperature();           
    
    string getDeviceType();    
    string getStatus();         
};

#endif 
