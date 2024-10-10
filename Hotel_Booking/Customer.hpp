#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "thread"
#include "mutex"

static mutex bookings_mutex;
#include "Room.hpp"

using namespace std;
class Customer
{
private:
    string name;
    int phone_number;
    vector<Room> rooms;

public:
    Customer(string _name, int _phone_number);
    ~Customer();
    void booking_room(Room &_room);
    void cancel_room(Room &_room);
    void list_rooms_is_booked();
};
#endif
