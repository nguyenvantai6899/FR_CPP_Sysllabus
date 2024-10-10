#include "Customer.hpp"

Customer::Customer(string _name, int _phone_number)
{
    name = _name;
    phone_number = _phone_number;
}

Customer::~Customer() { cout << "Customer is destroyed" << endl; };

void Customer::booking_room(Room &_room)
{
    if (_room.is_available())
    {
        lock_guard<mutex> lock(bookings_mutex);
        rooms.push_back(_room);
        _room.set_room_status(false);
    }
}
void Customer::cancel_room(Room &_room)
{
    auto _room_adr = find_if(rooms.begin(), rooms.end(),
                             [&_room](Room &_r)
                             {
                                 return _r.get_room_id() == _room.get_room_id();
                             });

    if (_room_adr != rooms.end())
    {
        rooms.erase(_room_adr);
        _room.set_room_status(true);
        cout << "Room is canceled" << endl;
    }
    else
    {
        cout << "Room is not found" << endl;
    }
}
void Customer::list_rooms_is_booked()
{
    for (auto &i : rooms)
    {
        i.display();
    }
}