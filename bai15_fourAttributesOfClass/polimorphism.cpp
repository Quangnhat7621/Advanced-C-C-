#include <iostream>

using namespace std;

class tinhToan{
    public:
        int tong(int a, int b);
        double tong(double a, double b);
        int tong(int a, int b, int c);

};

int tinhToan::tong(int a, int b)
{
    return a + b;
}

double tinhToan::tong(double a, double b)
{
    return a + b;
}

int tinhToan::tong(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    tinhToan A;
    printf("result: %d\n", A.tong(2, 5));
    printf("result: %d\n", A.tong(2, 5, 7));
    printf("result: %f\n", A.tong(2.2, 3.3));
}