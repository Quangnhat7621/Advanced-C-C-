#include <iostream>
#include <map>
#include<string>

using namespace std;

map<string, string> Sinhvien;

map<uint8_t, string> data;

int main()
{
    Sinhvien["Name"] = "Nhat";
    Sinhvien["Age"] = "22";
    Sinhvien["ID"] = "20119148";

    data[0] = "Bao";
    data[1] = "14";
    data[2] = "20119149";

    for(auto i: Sinhvien)
    {
        cout<<"key:"<<i.first<<"\t value:"<<i.second<<endl;
    }

    for(auto j: data)
    {
        cout<<"key:"<<j.first<<"\t value:"<<j.second<<endl;
    }
}
