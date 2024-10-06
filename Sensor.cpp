#include "Sensor.h"

void Sensor::addDevice(Observer *device)
{
    devices.push_back(device);
}


void Sensor::removeDevice(Observer *device)
{
    auto it = remove(devices.begin(), devices.end(), device);
    if(it != devices.end())
    {
        devices.erase(it, devices.end()); 
    }
}

void Sensor::notifyDevices()
{
    for(Observer *deviceCount : devices)
    {
        deviceCount->update();
    }
}


void Sensor::detectMotion()
{
    cout << "Sensor: Motion detected!" << endl;
    notifyDevices();
}