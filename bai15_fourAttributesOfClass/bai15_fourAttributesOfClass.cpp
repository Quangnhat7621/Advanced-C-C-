#include <iostream>
#include <string>

using namespace std;

class doiTuong{
    public:
        string ten;
        int tuoi;
        static int diachi;
};
int doiTuong::diachi;

class sinhVien : public doiTuong{
    public:
        int mssv;           // declare new property
};

int main()
{
    sinhVien A;
    
    doiTuong B, C;
    
    printf("dc %p:\n", &(B.diachi));
    printf("dc %p:\n", &(C.diachi));
    printf("dc %p:\n", &(A.diachi));

}

