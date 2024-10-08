#include "Thermostat.h"

Thermostat::Thermostat()
{
    temperature = 20;
    isOn = false;
} 


void Thermostat::toggleOn()
{
    isOn = true;
    cout << "Thermostat is on." << endl;
}

void Thermostat::toggleOff()
{
    isOn = false;
    cout << "Thermostat is off." << endl;
}

void Thermostat::toggle()
{
    isOn = !isOn;
    cout << "Thermostat toggled to " << (isOn ? "on." : "off.") << endl;
}

string Thermostat::getStatus() const
{
    if(isOn)
    {
        return "on, temperature: " + to_string(temperature) + "C";
    }
        
    else
    {
        return "off";
    }    
}

void Thermostat::performAction(const string& action)
{
    if(action == "ToggleOn")
    {
        toggleOn();
    }

    else if(action == "ToggleOff")
    {
        toggleOff();
    }

    else if(action == "Toggle")
    {
        toggle();
    }

    else if(action.find("SetTemperature") != string::npos)
    {
        size_t position = action.find(":");

        if(action.find(":") != string::npos)
        {
            double temp = stod(action.substr(position + 1));
            setTemperature(temp);
        }
        else
        {
            cout << "Invalid temperature format." << endl;
        }
    }
    
    else
    {
        cout << "Invalid action for Thermostat." << endl;
    }
}

string Thermostat::getDeviceType() const
{
    return "Thermostat";
}

void Thermostat::setTemperature(double temp)
{
    temperature = temp;
    cout << "Thermostat temperature set to " << temperature << "C." << endl;
}

double Thermostat::getTemperature() const
{
    return temperature;
}
