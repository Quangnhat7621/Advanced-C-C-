#include <iostream>
#include <string>

// lop con co the truy cap den protected va public trong lop cha
// khi chi muon cho lop con sua doi thong tin cua lop cha, nhung khong muon cho doi tuong truy cap thi su dung public

using namespace std;

class doiTuong{
    public:
        string ten;
        int tuoi;
        int lop;
        void inThongTin();
        void nhapThongTin(string ten, int tuoi, int lop);
};

void doiTuong::nhapThongTin(string ten, int tuoi, int lop)
{
    doiTuong::ten = ten;
    doiTuong::tuoi = tuoi;
    doiTuong::lop = lop;
}

void doiTuong::inThongTin()
{
    cout<<"ten: "<<doiTuong::ten<<endl;
    cout<<"tuoi: "<<doiTuong::tuoi<< endl;
    cout<<"lop: "<<doiTuong::lop<<endl;
}



// sinhVien class inherit all properties and methods in public in doiTuong class
// syntax   class sinhVien : public doiTuong{};          use ":" to inherit
class sinhVien : public doiTuong{
    public:
        int mssv;           // declare new property
        void nhapThongTin(string ten, int tuoi, int lop, int mssv);     //declear new method has the same name with method  
                                                                        // in parent calss but it has a new content (overwrite)
        void inThongTin();
};

// new method in sinhVien class have the same name wiht method in doiTuong class
void sinhVien::nhapThongTin(string ten, int tuoi, int lop, int mssv)    
{
    sinhVien::ten = ten;
    sinhVien::tuoi = tuoi;
    sinhVien::lop = lop;
    sinhVien::mssv = mssv;  // new content that make different from the method "nhapThongTin" in doiThuong class
}

void sinhVien::inThongTin()

{
    cout<<"ten: "<<sinhVien::ten<<endl;
    cout<<"tuoi: "<<sinhVien::tuoi<< endl;
    cout<<"lop: "<<sinhVien::lop<<endl;
    cout<<"mssv:"<<sinhVien::mssv;  // new content that make different from the method "inThongTin" in doiThuong class
}

int main()
{
    sinhVien A;
    A.nhapThongTin("Nhat", 22, 15, 20019148);
    A.inThongTin();
    

}