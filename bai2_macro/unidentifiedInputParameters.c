#include<stdio.h>

#define test(...) __VA_ARGS__                   // __VA_ARGS__ will replaced by anything filled in  ...

int main()
{
    test(int a = 10; int b = 20; int c = 5);    
    printf("a: %d \t b:%d\t c:%d\n", a, b, c);
}