#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>

using namespace std;

class Room
{
private:
    int roomId;
    string roomType;
    bool roomStatus;

public:
    Room(int _roomId, string _roomType, bool _roomStatus);
    ~Room();

    void display();
    bool is_available();
    void set_room_status(bool _status);
    int get_room_id();
    void booking_room();
};

#endif
