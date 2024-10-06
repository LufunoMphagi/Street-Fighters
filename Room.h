#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "SmartDevice.h"
#include <algorithm>
#include <iostream>
using namespace std;


class Room
{
    private:
    string name;
    vector<SmartDevice*> devices;

    public:
    Room(const string& roomName);
    ~Room();
    string getName() const;

    void addDevice(SmartDevice* device);
    void removeDevice(SmartDevice* device);
    const vector<SmartDevice*>& getDevices() const;
};

#endif 
