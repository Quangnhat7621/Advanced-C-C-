# Advanced-C-C-
extended C/C++ knowledge


"->" refer  to instructions

# BAI2_MACRO

'''

    #define max 10;         -> nomatter where max located, the compiler will replace it by 10

    #ifndef MAX             -> if the MAX is not defined, the content(statement1, statement2) between #ifndef and #endif will execute 
    statement1;
    statement2;
    #endif

'''

Incontrast to ifndef we have ifdef

-----------------------------------------------------Conditional macro

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

------------------------------------------------Creating a new variable using macro

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
        variable(int, a);                           // when "runing variable(int, a)" the compiler will replace "variable(int, a)"" by "int a;"
        variable1(b);
        variable2(c);
        b = 10;
        a = 5;
        charc = 'A';
        printf("value: %d\n", b);
        printf("value: %d\n", a);
        printf("value: %c\n", charc);

    }

-------------------------------------------------------Creating a function using macro
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

--------------------------------------------------------Unidentified_ipnutParameters


    #define test(...) __VA_ARGS__                   // __VA_ARGS__ will replaced by anything filled in  "..."

    int main()
    {
        test(int a = 10; int b = 20; int c = 5);    
        printf("a: %d \t b:%d\t c:%d\n", a, b, c);
    }

*****************************************************bai11_STACK

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h> 

// stack is a LIFO(last in first out)

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

********************************************************bai14_CLASS

Object only can access to the propterty and method in the public in its class

the method can access to the content in private and protected in its class

Instead of Define the function inside class, we can declare a header inside class and write the conten outside 

We use "::" to access the method inside class
------------Example
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


-----------------------------------------------------------------KETHUA(INHERITANCE)


// lop con co the truy cap den protected va public trong lop cha
// khi chi muon cho lop con sua doi thong tin cua lop cha, nhung khong muon cho doi tuong truy cap thi su dung public



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