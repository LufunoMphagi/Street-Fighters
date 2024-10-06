#ifndef SENSOR_H
#define SENSOR_H

#include "Observer.h"
#include <vector>
#include <algorithm>
using namespace std;

class Sensor
{
    private:
    vector<Observer*> devices; 

    public:
    void addDevice(Observer* device);
    void removeDevice(Observer* device);
    void notifyDevices();
    void detectMotion();
};

#endif 
