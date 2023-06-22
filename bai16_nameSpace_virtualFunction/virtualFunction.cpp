#include <iostream>

class sinhVien
{
    public:
        virtual char *string()
        {
            return (char *)"Hello world";
        }
        void display()
        {
            printf("Test: %s\n", string());
        }
};

class hocSinh : public sinhVien
{
    public:
        char *string()
        {
            return (char *)"This is test";
        }
};
int main()
{
    sinhVien sv;
    sv.display();

    hocSinh hs;
    hs.display();

    printf("test: %s\n", hs.string());
}