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

class TestCommand : public Command
{
    public:
    void execute() override
    {
        cout << "TestCommand executed." << endl;
    }
};

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
    
    kitchenLight.toggle();

    kitchenLight.toggleOn();
    cout << "Kitchen Light Status: " << kitchenLight.getStatus() << endl;

    frontDoorLock.lock();
    cout << "Front Door Lock Status: " << frontDoorLock.getStatus() << endl;

    frontDoorLock.unlock();
    cout << "Front Door Lock Status: " << frontDoorLock.getStatus()  << endl;

    frontDoorLock.toggleOff();
    frontDoorLock.getStatus();
    frontDoorLock.performAction("ToggleOn");
    frontDoorLock.getDeviceType();
    frontDoorLock.lock();
    frontDoorLock.unlock();


    // Test Thermostat
    cout << "\nTesting Thermostat" << endl;
    thermostat.setTemperature(21.5);
    cout << "Thermostat Set Temperature: " << thermostat.getTemperature() << "°C" << endl;

    cout << "\nCreating Rooms and Sections" << endl;
    Room livingRoom("Living Room");
    livingRoom.addDevice(&livingRoomLight);
    livingRoom.addDevice(&thermostat);

    Section house("House");
    house.addRoom(&livingRoom);

    cout << "Devices in " << livingRoom.getName() << "" << endl;
    for(auto deviceCount : livingRoom.getDevices())
    {
        deviceCount->getStatus();
    }

    thermostat.toggleOn();
    thermostat.toggleOff();
    thermostat.toggle();
    thermostat.getStatus();
    thermostat.performAction("ToogleOff");
    thermostat.getDeviceType();

    // Test Macro Command to turn off all lights
    cout << "\nTesting MacroRoutine to Turn Off All Lights" << endl;
    TurnOffAllLights execute;
    MacroRoutine routine;
    routine.execute();

    cout << "Living Room Light Status after Macro: " << livingRoomLight.getStatus()  << endl;
    cout << "Kitchen Light Status after Macro: " << kitchenLight.getStatus() << endl;


    Command* testCommand = new TestCommand();
    routine.addProcedure(testCommand);
    routine.removeProcedure();

   // delete testCommand;

    // Test Observer pattern with sensors and alarms
    cout << "\nTesting Sensor and Alarm (Observer pattern)" << endl;
    Sensor motionSensor;
    Alarm houseAlarm;
    motionSensor.addDevice(&houseAlarm);  
    motionSensor.detectMotion();      

    // Test Smart Thermostat Integration (Strategy Pattern)
    cout << "\nTesting SmartThermostatIntegrator using ownedd thermostat" << endl;
    SmartThermostatIntegrator integrator;
    integrator.setTemperature(20);  
    

    cout << "Current temperature: " << integrator.getTemperature() << "°C" << endl;
    cout << "Device type: " << integrator.getDeviceType() << endl;
    cout << "Status: " << integrator.getStatus() << endl;     

    cout << "\nTesting SmartThermostatIntegrator using external thermostat" << endl;
    OldThermostat externalThermostat;
    SmartThermostatIntegrator integratorWithExternal(&externalThermostat);
    integratorWithExternal.setTemperature(25);  

    cout << "External Thermostat Temperature: " << integratorWithExternal.getTemperature() << "°C" << endl;
    cout << "Status: " << integratorWithExternal.getStatus() << endl;

    return 0;
}
