# Advanced-C-C-
extended C/C++ knowledge


"->" refer  to instructions

BAI2_MACRO

    #define max 10;         -> nomatter where max located, the compiler will replace it by 10

    #ifndef MAX             -> if the MAX is not defined, the content(statement1, statement2) between #ifndef and #endif will execute 
    statement1;
    statement2;
    #endif

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