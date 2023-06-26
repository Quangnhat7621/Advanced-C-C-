#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class diem
{
    private:
        int x;
        int y;
    public:
        diem(float x = 0, float y = 0)
        {
            diem::x = x;
            diem::y = y;
        }
        void ganGiaTri(float x, float y);
        float toaDo_x();
        float toaDo_y();
};

void diem::ganGiaTri(float x, float y)
{
    diem::x = x;
    diem::y = y;
}
float diem::toaDo_x()
{
    return x;
}
float diem::toaDo_y()
{
    return y;
}

class phepToan_OXY
{
    private:
        diem A;
        diem B;
        diem C;
        typedef enum
        {
            khoangCach, dienTich
        }loaiPhepToan;
        loaiPhepToan phepToan;
    public:
        
        void tinhToan(diem A, diem B);
        void tinhToan(diem A, diem B, diem C);
        float layKhoangCach();
        float layDienTich();
};

void phepToan_OXY::tinhToan(diem A, diem B)
{
    phepToan = khoangCach;
    phepToan_OXY::A = A;
    phepToan_OXY::B = B;
}

void phepToan_OXY::tinhToan(diem A, diem B, diem C)
{
    phepToan = dienTich;
    phepToan_OXY::A = A;
    phepToan_OXY::B = B;
    phepToan_OXY::C = C;
}

float phepToan_OXY::layKhoangCach()
{
    if(phepToan == khoangCach)
    {
        float khoangCach = sqrt( pow((B.toaDo_x() - A.toaDo_x()),2) + pow((B.toaDo_y() - A.toaDo_y()),2));
        return khoangCach;
    }
    else
    {
        cout<<"phepToan sai"<<endl;
    }
}

float phepToan_OXY::layDienTich()
{
    if(phepToan == dienTich)
    {
        float dienTich = 0.5 * fabs( A.toaDo_x()*(B.toaDo_y() - C.toaDo_y()) +B.toaDo_x()*(C.toaDo_y() - A.toaDo_y()) + C.toaDo_x()*(A.toaDo_y() - B.toaDo_y()) );
        return dienTich;
    }
    else
    {
        cout<<"phepToan sai"<<endl;
    }
}

int main()
{
    diem A(2,1), B(3,2);
    phepToan_OXY phepToan1;
    phepToan1.tinhToan(A, B);
    cout<<"result: "<< phepToan1.layKhoangCach()<<endl;

    A.ganGiaTri(3,2);
    phepToan1.tinhToan(A, B);
    cout<<"result: "<< phepToan1.layKhoangCach()<<endl;

    phepToan_OXY phepToan2;
    diem D(2,1), E(2, 0), F(4, 0);
    phepToan2.tinhToan(D, E, F);
    cout<<"dienTichLa: "<<phepToan2.layDienTich()<<endl;

}