#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>     // add stdbool.h lib to use boolean data type

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
