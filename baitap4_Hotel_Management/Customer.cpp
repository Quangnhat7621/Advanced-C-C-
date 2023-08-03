#include<iostream>
#include<string>
#include<vector>
using namespace std;
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
        uint8_t idRoom;
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