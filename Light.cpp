#include "Light.h"

Light::Light() 
{
    isOn = false;
}

void Light::toggleOn()
{
    isOn = true;
    cout << "Light is on." << endl;
}

void Light::toggleOff()
{
    isOn = false;
    cout << "Light is off." << endl;
}

void Light::toggle()
{
    isOn = !isOn;
    cout << "Light toggled to " << (isOn ? "on." : "off.") << endl;
}

string Light::getStatus() const
{
    return isOn ? "on" : "off";
}


void Light::performAction(const string& commandAction)
{
    if(commandAction == "ToggleOn")
    {
        toggleOn();
    }
    
    else if(commandAction == "ToggleOff")
    {
        toggleOff();
    }

    else if(commandAction == "Toggle")
    {
        toggle();
    }

    else
    {
        cout << "Invalid action for Light." << endl;
    }
}

string Light::getDeviceType() const
{
    return "Light";
}
