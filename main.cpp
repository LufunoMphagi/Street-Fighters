#include "Sensor.h"
#include "SmartDevice.h"
#include "Light.h"
#include "Alarm.h"
#include "Command.h"
#include "DoorLock.h"
#include "MacroRoutine.h"
#include "Observer.h"
#include "Room.h"
#include "Section.h"
#include "SmartThermostatIntegrator.h"
#include "Thermostat.h"
#include "TurnOffAllLights.h"
using namespace std;

int main()
{
    Light livingRoomLight;
    Light kitchenLight;
    DoorLock frontDoorLock;
    Thermostat thermostat;


    cout << "Testing Lights and DoorLock: " << endl;
    livingRoomLight.toggle();
    livingRoomLight.getDeviceType();
    livingRoomLight.performAction("ToogleOn");

    livingRoomLight.toggleOn();
    cout << "Living Room Light Status: " << livingRoomLight.getStatus() << endl;

    livingRoomLight.toggleOff();
    cout << "Living Room Light Status: " << livingRoomLight.getStatus() << endl;
    

    kitchenLight.toggleOn();
    cout << "Kitchen Light Status: " << kitchenLight.getStatus() << endl;

    frontDoorLock.lock();
    cout << "Front Door Lock Status: " << frontDoorLock.getStatus() << endl;

    frontDoorLock.unlock();
    cout << "Front Door Lock Status: " << frontDoorLock.getStatus()  << endl;

    // Test Thermostat

    // Test Macro Command to turn off all lights
    


    return 0;
}
