#include<stdio.h>
#define variable(type, name) type name          // create a new variable  by macro

#define variable1(name) int name                // effective as above but the type of data is define in macro


// it is also use for creating new variables but it create more than one variable
#define variable2(name) int int##name;      \   
char char##name;    \
double double##name; 
// "\" used for Line break and the last one don't use



// defined a function using macro
#define Display(functionName, name, age, class)             \
void functionName()                                         \
{                                                           \
    printf("student name: %s\n", #name);                    \
    printf("age: %d\n", age);                               \
    printf("class: %s\n", #class);                          \
}

Display(hsA, Tran Quang Nhat, 22, 20);

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

    hsA();
    

}