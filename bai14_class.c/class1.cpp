#include <iostream>
#include <string>

using namespace std;

class sinhVien{
    public:
        void enterData(string _name, int _className, int _age);
        void display();

    private:
        int age;
        int className;
        string name;

};

void sinhVien::enterData(string _name, int _className, int _age)
{
    sinhVien::name = _name;
    className = _className;
    age = _age;
}

void sinhVien::display()
{
    
    cout<<"student name: "<<name<<endl;
    cout<<"student age: "<<age<< endl;
    cout<<"class name: "<<className<<endl;
}

int main()
{
    sinhVien A, B;
    A.enterData("Tran Quang Nhat", 15, 22);
    B.enterData("Tran Gia Bao", 8, 14);

    A.display();
    B.display();
}