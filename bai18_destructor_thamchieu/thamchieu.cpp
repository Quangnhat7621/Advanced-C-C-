#include <iostream>

using namespace std;



void test(int a, int *b, int &c) // int a, int *b là các biến tạm dùng để lưu giá trị, hay còn gọi là tham trị, tốn bộ nhó vì phải lưu dư liệu tạm thời
                                // còn &c là chỉ trực tiếp đến biến cục bộ đã được khởi tạo ở ngoài, 
                                //ta có thể sửa giá trị trục tiếp mà không cần qua biến trung gian, nên không tốn thêm bộ nhớ
{          
    a = 10, *b = 20, c = 30;

}

int main()
{
    int a = 0, b = 0, c = 0;
    test(a, &b, c);
    cout<<"a: "<< a << endl;
    cout<<"b: "<< b << endl;
    cout<<"c: "<< c << endl;
    return 0;
}