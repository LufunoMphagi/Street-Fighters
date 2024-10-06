#include "SmartThermostatIntegrator.h"
#include <iostream>
SmartThermostatIntegrator::SmartThermostatIntegrator(){}
OldThermostat::OldThermostat()
{
    currentTemperature = 20;
} 

void OldThermostat::setLegacyTemperature(int temp)
{
    currentTemperature = temp;
}

int OldThermostat::getLegacyTemperature()
{
    return currentTemperature;
}

SmartThermostatIntegrator::SmartThermostatIntegrator(OldThermostat* oldThermostat)
{
    legacyThermostat = oldThermostat;
}
    

void SmartThermostatIntegrator::setTemperature(int temp)
{
    legacyThermostat->setLegacyTemperature(temp);
}

int SmartThermostatIntegrator::getTemperature()
{
    return legacyThermostat->getLegacyTemperature();
}

string SmartThermostatIntegrator::getDeviceType()
{
    return "Thermostat";
}

string SmartThermostatIntegrator::getStatus()
{
    return "Current temperature: " + to_string(getTemperature()) + "°C";
}
