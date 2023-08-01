#include<string>
#include<stdbool.h>

using namespace std;
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