#include<stdio.h>
#include<stdint.h>

void inverse(uint8_t length ,uint8_t arr[])
{
    uint8_t _array [length];
    for(uint8_t i = length; i > 0; i--)
    {
        _array[8 - i] = arr[i]; 
    }

    for(uint8_t i = 0; i < length, i++)
    {
        printf()
    }
}