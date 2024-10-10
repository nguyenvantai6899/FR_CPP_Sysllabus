#include "Room.hpp"

Room::Room(int _roomId, string _roomType, bool _roomStatus)
{
    roomId = _roomId;
    roomType = _roomType;
    roomStatus = _roomStatus;
}

Room::~Room()
{
}

void Room::display()
{
    std::cout << "Room number: " << roomId << ", room type: " << roomType
              << ", status: " << (roomStatus ? "Available" : "Not available") << std::endl;
}

bool Room::is_available()
{
    return roomStatus;
}
void Room::set_room_status(bool _status)
{
    roomStatus = _status;
}
int Room::get_room_id()
{
    return roomId;
}
void Room::booking_room()
{
    if (is_available())
    {
        roomStatus = false;
    }
}
