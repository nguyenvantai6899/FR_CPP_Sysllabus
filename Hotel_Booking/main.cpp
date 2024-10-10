#include <iostream>
#include "Room.hpp"
#include "Customer.hpp"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    vector<Room> rooms;
    Room room1(1, "vip1", true);
    Room room2(2, "vip2", true);
    Room room3(3, "vip3", true);

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);

    Customer customer1("Customer1", 12345);
    customer1.booking_room(room1);
    customer1.booking_room(room2);
    customer1.list_rooms_is_booked();

    customer1.cancel_room(room1);
    customer1.cancel_room(room3);
    customer1.list_rooms_is_booked();
    return 0;
}
