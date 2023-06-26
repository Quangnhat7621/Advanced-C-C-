#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
    private: 
        float TOAN;
        float LY;
        float HOA;
        float DIEM_TRUNG_BINH;
        string TEN;
    
    public:
        //constructor
        SinhVien(float toan, float ly, float hoa, string ten)
        {
            TOAN = toan;
            LY = ly;
            HOA = hoa;
            TEN = ten;
        }
        //set value
        void setToan(float toan);
        void setLy(float ly);
        void setHoa(float hoa);
        void setTen(string ten);
        //get value
        float getToan();
        float getLy();
        float getHoa();
        string getTen();
        float getDiemTrungBinh();

        void hienThi();
};


// change value
void SinhVien::setToan(float toan)
{
    TOAN = toan;
}

void SinhVien::setLy(float ly)
{
    LY = ly;
}

void SinhVien::setHoa(float hoa)
{
    HOA = hoa;
}

void SinhVien::setTen(string ten)
{
    TEN = ten;
}


// get value
float SinhVien::getToan()
{
    return TOAN;
}

float SinhVien::getLy()
{
    return LY;
}

float SinhVien::getHoa()
{
    return HOA;
}

string SinhVien::getTen()
{
    return TEN;
}

float SinhVien::getDiemTrungBinh()
{
    return TOAN;
}

// display
void SinhVien::hienThi()
{
    cout<<"ten HS:"<<TEN<<"\tdiem toan:"<< TOAN<<"\t"<<"diem ly"<<LY<<"\t"<<"diem hoa:"<< HOA <<endl;
}

int main()
{
    SinhVien A(9, 9, 9, "nhat");
    A.hienThi();
    cout<<"lay diem toan:"<< A.getToan()<<endl;
}