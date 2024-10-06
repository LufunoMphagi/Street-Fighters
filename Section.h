#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <vector>
#include "Room.h"
#include <iostream>
#include <algorithm>

class Section
{
    private:
    string name;
    vector<Room*> rooms;

    public:
    Section(const string& sectionName);
    ~Section();

    string getName() const;
    void addRoom(Room* room);
    void removeRoom(Room* room);
    const vector<Room*>& getRooms() const;
};

#endif 
