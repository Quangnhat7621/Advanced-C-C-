#include<iostream>
using namespace std;

int main()
{
    typedef enum
    {
        A, 
        B, 
        C
    }typeA;

    typeA a;
    int b;
    cout<<"nhap:";
    cin>>b;
    if(b == 0)
    {
        a = A;
    }
    else if(b == 1)
    {
        a = B;
    }
    else
    {   
        a = C;
    }
    
}