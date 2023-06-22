#include <iostream>
using namespace std;

template<typename var>
var tong( var a, var b)
{
    return (var)(a + b);
}

template<typename var1, typename var2>
var2 tong1(var1 a, var2 b)
{
    return var2(a + b);
}

int main()
{
    printf("result: %f \n", tong(2.5, 6.3));
    printf("result: %f \n", tong1(2, 6.6));
}