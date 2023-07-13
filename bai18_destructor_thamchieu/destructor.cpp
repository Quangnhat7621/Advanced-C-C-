#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
    private:
        int ID;
        int *ptr = nullptr;
        string name;
    public:
        SinhVien()
        {
            static int id;
            ptr = &id;
            ID = id;
            id++;
        }
        ~SinhVien()
        {
            *ptr = 0;
            name  = "sinh vien: ";
            name.push_back(ID + 48);
            cout<<"destructor duoc goi \t";
            cout<<name<<endl;
        }
        void inThongTin()
        {
            cout<<"ID: "<<this->ID<<endl;
        }

};

void test1()
{
    SinhVien sv1, sv2, sv3;
    sv1.inThongTin();
    sv2.inThongTin();
    sv3.inThongTin();
}

int main()
{
    test1();
    SinhVien sv4;
    sv4.inThongTin();

    return 0;
}