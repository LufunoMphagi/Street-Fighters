#include "Section.h"

Section::Section(const string& sectionName)
{
    name = sectionName;
}

Section::~Section()
{
    for(auto roomsCount : rooms)
    {
        delete roomsCount;
    }
}

string Section::getName() const
{
    return name;
}

void Section::addRoom(Room* room)
{
    rooms.push_back(room);
    cout << "Room \"" << room->getName() << "\" added to section \"" << name << "\"." << endl;
}

void Section::removeRoom(Room* room)
{
    auto it = remove(rooms.begin(), rooms.end(), room);

    if(it != rooms.end())
    {
        rooms.erase(it, rooms.end());
        delete room;
        cout << "Room \"" << room->getName() << "\" removed from section \"" << name << "\"." << endl;
    }

    else
    {
        cout << "Room not found in section \"" << name << "\"." << endl;
    }
}

const vector<Room*>& Section::getRooms() const
{
    return rooms;
}
