#include <iostream>
#include<stdbool.h>

using namespace std;

class Room
{
    private:
        uint8_t roomNumber;
        bool isCleaning;
        bool isBooked;
    
    public:
        Room(uint8_t number);
        uint8_t getRoomNumber();
        bool isAvaiable();
        void checkIn();
        void checkOut();
        void bookRoom();
};
Room::Room(uint8_t number)
{
    roomNumber = number;
}
uint8_t Room::getRoomNumber()
{
    return roomNumber;
}
bool Room::isAvaiable()
{
    return !isBooked && !isCleaning;
}
void Room::bookRoom()
{
    isBooked = true;
}
void Room::checkIn()
{
    isBooked = true;
}
void Room::checkOut()
{
    isBooked = false;
    isCleaning = true;
}

