# Advanced-C-C-
extended C/C++ knowledge


"->" refer  to instructions

# BAI2_MACRO

```php

#define max 10;         -> nomatter where max located, the compiler will replace it by 10

#ifndef MAX             -> if the MAX is not defined, the content(statement1, statement2) between #ifndef and #endif will execute 
statement1;
statement2;
#endif

```

> Incontrast to ifndef we have ifdef

## Conditional macro

```php

    #if MAX > 20                      -> if MAX > 20 then  "void display() {printf("MAX > 20\n"); }" is defined
    void display()
    {
        printf("MAX > 20\n");
    }
    #elif MAX == 20                   -> else if MAX = 20 then "void display() {printf("MAX = 20\n"); }" is defined
    void display()
    {
        printf("MAX = 20\n");
    }
    #else                             -> else MAX < 20 then "void display() {printf("MAX <> 20\n"); }" is defined
    void display()
    {
        printf("MAX < 20\n");
    }

    #endif

```

## Creating a new variable using macro

> "\" used for Line break and the last one don't use
> "##" use two "##" to connect two string

```php
#define variable(type, name) type name          // create a new variable  by macro

#define variable1(name) int name                // effective as above but the type of data is define in macro


// the code below is also use for creating new variables but it create more than one variable
#define variable2(name) int int##name;      \   
char char##name;    \
double double##name; 
// "\" used for Line break and the last one don't use
// "##" use two "##" to connect two string


int main()
{
    variable(int, a);                    // when "runing variable(int, a)" the compiler will replace "variable(int, a)"" by "int a;"
    variable1(b);
    variable2(c);
    b = 10;
    a = 5;
    charc = 'A';
    printf("value: %d\n", b);
    printf("value: %d\n", a);
    printf("value: %c\n", charc);

}
```

## Creating a function using macro

```php
#define Display(functionName, name, age, class)             \
void functionName()                                         \
{                                                           \
    printf("student name: %s\n", #name);                    \
    printf("age: %d\n", age);                               \
    printf("class: %s\n", #class);                          \
}
// using "#" to inform that "#name" is a string

Display(hsA, Tran Quang Nhat, 22, 20);
int main()
{
    hsA();
}
```
## Unidentified_ipnutParameters

```php
#define test(...) __VA_ARGS__                   // __VA_ARGS__ will replaced by anything filled in  "..."

int main()
{
   test(int a = 10; int b = 20; int c = 5);    
    printf("a: %d \t b:%d\t c:%d\n", a, b, c);
}
```

# bai11_STACK

![stack operating](https://cdn.buttercms.com/PuR6MmOQQdqAP6xfh6JO)

> stack is a LIFO(last in first out)

```php
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h> 



uint8_t size;                       // declare size as the length of stack
int8_t _index = -1;                 // declare and initialize value for _index 


// checking stack is full or not
bool isFull()
{
    if(_index == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// checking stack is empty or not
bool isEmpty()
{
    if(_index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// add a new value at the top of stack
void push(uint8_t arr[], uint8_t value)
{
    if(isFull())
    {
        printf("stack is full\n");
    }
    else
    {
        _index ++;
        arr[_index] = value;
    }
}

// remove a value at the top of stack
void rm(uint8_t arr[])
{
    if(isEmpty())
    {
        printf("stack is empty\n");
    }
    else
    {
        _index --;
        arr[_index + 1] = '\0';
    }
}

// take out the top value of stack
uint8_t pop(uint8_t arr[])
{
    if(isEmpty())
    {
        printf("stack is empty\n");

    }
    else
    {
        _index --;
        return arr[_index + 1];
    }
}

// take the size of stack
uint8_t stackSize()
{
    return _index + 1;
}

int main()
{
    size = 5;               // initialize the size of stack
    uint8_t stack[size];      // create a array of size 5
    push(stack, 1);           // put in first value in stack
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    // take out value of stack
    printf("take out value: %d\n", pop(stack));
    printf("take out value: %d\n", pop(stack));

    // remove the top value on stack
    rm(stack);    
    printf("take out value: %d\n", pop(stack));

    // get stack size
    printf("size of stack:%d\n", stackSize());
    rm(stack);
    printf("take out value: %d\n", pop(stack));
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("size of stack:%d\n", stackSize());
}
```

# bai14_CLASS

> Object only can access to the propterty and method in the public in its class

> the method can access to the content in private and protected in its class

> Instead of Define the function inside class, we can declare a header inside class and write the conten outside 

> We use "::" to access the method inside class
### Example

```php
    class sinhVien{
        public:
            void enterData(string _name, int _className, int _age);
            void display();

        private:
            int age;
            int className;
            string name;

    };

    void sinhVien::enterData(string _name, int _className, int _age)
    {
        name = _name;
        className = _className;
        age = _age;
    }

    void sinhVien::display()
    {
        
        cout<<"student name: "<<name<<endl;
        cout<<"student age: "<<age<< endl;
        cout<<"class name: "<<className<<endl;
    }
```

## KETHUA(INHERITANCE)


> lop con co the truy cap den protected va public trong lop cha
> khi chi muon cho lop con sua doi thong tin cua lop cha, nhung khong muon cho doi tuong truy cap thi su dung public


```php
    class doiTuong{
        public:
            string ten;
            int tuoi;
            int lop;
            void inThongTin();
            void nhapThongTin(string ten, int tuoi, int lop);
    };

    void doiTuong::nhapThongTin(string ten, int tuoi, int lop)
    {
        doiTuong::ten = ten;
        doiTuong::tuoi = tuoi;
        doiTuong::lop = lop;
    }

    void doiTuong::inThongTin()
    {
        cout<<"ten: "<<doiTuong::ten<<endl;
        cout<<"tuoi: "<<doiTuong::tuoi<< endl;
        cout<<"lop: "<<doiTuong::lop<<endl;
    }



    // sinhVien class inherit all properties and methods in public in doiTuong class
    // syntax   class sinhVien : public doiTuong{};          use ":" to inherit
    class sinhVien : public doiTuong{
        public:
            int mssv;           // declare new property
            void nhapThongTin(string ten, int tuoi, int lop, int mssv);     //declear new method has the same name with method  
                                                                            // in parent calss but it has a new content (overwrite)
            void inThongTin();
    };

    // new method in sinhVien class have the same name wiht method in doiTuong class
    void sinhVien::nhapThongTin(string ten, int tuoi, int lop, int mssv)    
    {
        sinhVien::ten = ten;
        sinhVien::tuoi = tuoi;
        sinhVien::lop = lop;
        sinhVien::mssv = mssv;  // new content that make different from the method "nhapThongTin" in doiThuong class
    }

    void sinhVien::inThongTin()

    {
        cout<<"ten: "<<sinhVien::ten<<endl;
        cout<<"tuoi: "<<sinhVien::tuoi<< endl;
        cout<<"lop: "<<sinhVien::lop<<endl;
        cout<<"mssv:"<<sinhVien::mssv;  // new content that make different from the method "inThongTin" in doiThuong class
    }

    int main()
    {
        sinhVien A;
        A.nhapThongTin("Nhat", 22, 15, 20019148);
        A.inThongTin();
        

    }

```

# four attributes of class

> class form don't waste memory. when we create an object then the object has a memory space.

### Example

```php
// class doiTuong don't waste memory space.
class doiTuong{
    public:
        string ten;
        int tuoi;
        int lop;
        void inThongTin();
        void nhapThongTin(string ten, int tuoi, int lop);
};

int main()
{
    doiTuong A; // object A take memory space
}
```
## static variable in class

> static variable in class must be declared outside class
> each object has one addressb but when objects access to static varible they have the same address

```php
#include <iostream>
#include <string>

using namespace std;

class doiTuong{
    public:
        string ten;
        int tuoi;
        static int diachi;
};
int doiTuong::diachi;

class sinhVien : public doiTuong{
    public:
        int mssv;           // declare new property
};

int main()
{
    sinhVien A;
    
    doiTuong B, C;
    
    printf("dc %p:\n", &(B.diachi));
    printf("dc %p:\n", &(C.diachi));
    printf("dc %p:\n", &(A.diachi));

}
```
> Object B,C belong to doiTuong class and object A belongs to sinhVien class, but A.diachi, B.diachi, C.diachi are the same. 

## Polymorphism(tính đa hình)
> Being able to create many method with the same name, but their input parametters must be different.
> depend on input parametters the corresponding function will  be called.

### example
``` php
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
```

## template


- Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu 
tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- Template trong C++ có 2 loại đó là function template & class template.
- Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì 
phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu 
dữ liệu khác nhau

```php

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
```

## namespace
> Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.
> Su dung using namespace de rut ngan cach goi
```php
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
```
## virtualFunction

> Hàm ảo (virtual function) là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất 
khi kế thừa cần phải định nghĩa lại.
> Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định 
nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có 
kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất.
> Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ 
trợ bởi nguồn ngữ C++.
> Lưu ý: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, 
nhưng ngược lại thì không được.
> Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử 
dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần 
của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.

```php
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
```