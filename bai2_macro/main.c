#include<stdio.h>



#ifndef MIN             // if MIN is not defined then define MIN 10
#define MIN 10
#endif


#ifdef MIN              // if MIN is defined then define MIN 20
#define MIN 20
#endif

#define MAX 10

#if MAX > 20
void display()
{
    printf("MAX > 20\n");
}
#elif MAX == 20
void display()
{
    printf("MAX = 20\n");
}
#else
void display()
{
    printf("MAX < 20\n");
}

#endif

#define tong(a,b) a+b   // replace tong(a,b) by a+b, it dont have data type

int main()
{
    printf("tong a va b: %d\n", tong(6,9));   
    printf("MIN: %d\n", MIN);                     
    display();
}