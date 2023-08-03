#include <iostream>
#include<stdbool.h>
#include<vector>
#include<iostream>
#define the_Number_Of_Room 15
int roomNumber[the_Number_Of_Room] = {101, 102, 103, 104, 105,
                                      201, 202, 203, 204, 205,
                                      301, 302, 303, 304, 305};


using namespace std;

class Room
{
    private:
        int roomNumber;
        bool isCleaning;
        bool isBooked;
    
    public:
        Room(int _roomNumber);
        int getRoomNumber();
        bool isAvaiable();
        void checkIn();
        void checkOut();
        void bookRoom();
        void showRoomStatus();
};
Room::Room(int number)
{
    roomNumber = number;
    isCleaning = false;
    isBooked = false;
}
int Room::getRoomNumber()
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

void Room::showRoomStatus()
{
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Room ID: "<< roomNumber <<"\t"<< "isCleaning: "<< isCleaning <<"\t"<< "isBooked: "<< isBooked << endl;
}

///////////////////////////////////////////////////////
typedef struct
{
    uint8_t day;
    uint8_t month;
    uint8_t year;
}typeDate;

typedef struct
{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}typeTime;

typedef enum
{
    IN,
    OUT
} typeStatus;

typedef struct
{
    typeDate date;
    typeTime time;
    typeStatus status;
}bookingHistory;

class Customer
{
    private:
        int idRoom;
        string customer_name;
        string customer_phoneNumber;
        string customer_address;
        vector <bookingHistory> customer_bookingHistories;
    public:
        Customer(string _customer_name, string _customer_phoneNumber, string customer_address);
        string customer_getName();
        string customer_getPhoneNumber();
        string customer_getAddress();
        void customer_addBookingHistory(bookingHistory bookingDetail);
        void customer_displayBookingHistories();
};

Customer::Customer(string _customer_name, string _customer_phoneNumber, string _customer_address)
{
    customer_name = _customer_name;
    customer_phoneNumber = _customer_phoneNumber;
    customer_address = _customer_address;
}

string Customer::customer_getName()
{
    return customer_name;
}

string Customer::customer_getPhoneNumber()
{
    return customer_phoneNumber;
}

string Customer::customer_getAddress()
{
    return customer_address;
}

void Customer::customer_addBookingHistory(bookingHistory bookingDetail )
{
    customer_bookingHistories.push_back(bookingDetail);
}

void Customer::customer_displayBookingHistories()
{
    for( bookingHistory history : customer_bookingHistories)
    {
        cout<<"date: "<<history.date.day<<":"<<history.date.month<<":"<<history.date.year<<"\t time: "<<history.time.hour<<":"<<history.time.minute<<":"<<history.time.second<<"\t status: "<<history.status<<endl;
    }
}


////////////////////////////////


class User
{
    private:
        string user_name;
        string user_password;
    public:
        User(string _user_name, string _user_password);
        string user_getUserName();
        bool authenticate( string passWord);
};
User::User(string _user_name, string _user_password)
{
    user_name = _user_name;
    user_password = _user_password;
}

string User::user_getUserName()
{
    return user_name;
}

bool User::authenticate(string password)
{
    return user_password == password;
}

typedef enum
{
    Receptionist,
    Maid,
    Chef,
    Security
} Jobtype;

typedef enum
{
    DayShift,
    NightShift
}Schedule;


class Employee
{
    private:
        string empl_name;
        string empl_phoneNumber;
        string empl_address;
        Schedule empl_schedule;
        Jobtype empl_jobType;
        User empl_user;
    public:
        Employee(string _empl_name, string _empl_phoneNumber, string _empl_address, Schedule _empl_schedule, Jobtype _empl_jobType, User _empl_user);
        string empl_getName(string password);
};
Employee::Employee(string _empl_name, string _empl_phoneNumber, string _empl_address, Schedule _empl_schedule, Jobtype _empl_jobType, User _empl_user)
{
    empl_name = _empl_name;
    empl_phoneNumber = _empl_phoneNumber;
    empl_address = _empl_address;
    empl_schedule = _empl_schedule;
    empl_jobType = _empl_jobType;
    empl_user = _empl_user;
}

string Employee::empl_getName(string password)
{
    if( empl_user.authenticate(password) || password == "admin" )
    {
        return empl_name;
    }
}

vector <Room> roomList;

void initialRoom()
{
    for(uint8_t i = 0; i < the_Number_Of_Room; i++)
    {
        Room room(roomNumber[i]);
        _roomList.push_back(room);
    }
}

void showRoomStatus()
{
    for(auto item : _roomList)
    {
        item.showRoomStatus();
    }
}


vector <Customer> customerList;

void addCustomer()
{
    string _customerName;
    string _customerPhoneNumber;
    string _customerAddress;
    cout<<"Enter customer name: ";
    cin>>_customerName;
    cout<<"Enter customer phone number: ";
    cin>>_customerPhoneNumber;
    cout<<"Enter customer address: ";
    cin>>_customerAddress;

    Customer _customer(_customerName, _customerName, _customerAddress);
    customerList.push_back(_customer);
    
}


void bookRoom()
{
    showRoomStatus();
    
}