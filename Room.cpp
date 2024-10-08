#include "Room.h"

Room::Room(const string& roomName) 
{
    name = roomName;
}

Room::~Room()
{
}

string Room::getName() const
{
    return name;
}

void Room::addDevice(SmartDevice* device)
{
    devices.push_back(device);
    cout << device->getDeviceType() << " added to " << name << "." << endl;
}

void Room::removeDevice(SmartDevice* device)
{
    auto it = remove(devices.begin(), devices.end(), device);

    if(it != devices.end())
    {
        devices.erase(it, devices.end());
        delete device;
        cout << device->getDeviceType() << " removed from " << name << "." << endl;
    }
    else
    {
        cout << "Device not found in " << name << "." << endl;
    }
}

const vector<SmartDevice*>& Room::getDevices() const
{
    return devices;
}
