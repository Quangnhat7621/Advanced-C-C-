#include <iostream>

using namespace std;

class parent
{
    public:
        int a = 20;
        virtual void display()
        {
            printf("class cha\n");
        }
};

class son : public parent
{
    public:
        int b = 30;
        void display()
        {
            printf("class con \n");
        }
};


int main()
{
    parent A;
    son B;
    printf("address A: %p\n", &A);
    printf("address B:%p\n", &B);
    printf("\n");
    B.display();

    parent *ptr;
    ptr = &B;

    ptr->display();
}