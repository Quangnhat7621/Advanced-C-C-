#include <iostream>

namespace conOngA
{
    int a = 10;
};

namespace conOngB
{
    int a = 20;
};


using namespace conOngA;
int main()
{
    // 2 bien a va b trung ten, nhung nam o 2 vung nho khac nhau
    printf("value: %d\n", conOngA::a);
    printf("value: %d\n", conOngB::a);

    // khi da su dung using namespace conOngA thi khi goi bien a- chinh la bien a trong conOngA
    printf("value: %d\n", a);
    
}