// coder: Tran Quang Nhat
// completed time 11:22 pm
// date: 06/11/2023
// duration: 1 hour

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

#define SIZE 50
#define MIN_VALUE 1
#define MAX_VALUE 100

void createArray(uint8_t arr[]){
    uint8_t i;

    // Khởi tạo seed cho hàm rand()
    srand(time(NULL));

    // Tạo mảng ngẫu nhiên trong phạm vi từ MIN_VALUE đến MAX_VALUE
    for (i = 0; i < SIZE; i++) {
        arr[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    }
}

// sorting array
void sort(uint8_t length, uint8_t _arr[])
{
    for(uint8_t i = 0; i < length - 1; i++)
    {
        for(uint8_t j = i + 1; j < length; j++)
        {
            if(_arr[i] > _arr[j])
            {
                uint8_t temp;
                temp = _arr[i];
                _arr[i] = _arr[j];
                _arr[j] = temp;
            }
        }
    }
}                             



bool findNumber(uint8_t _left, uint8_t _right , uint8_t arr[], uint8_t inputNumber)
{
    
    uint8_t centerPoint = _left + (_right - _left) / 2;     //  find mid index in array
    if((_right - _left) < 5)        // if the range is smaller than 5, we will find the number in range
    {
        for(uint8_t i = 0; i < (_right - _left) + 1; i++)
        {
            if(arr[_left + i] == inputNumber)   
            return true;
        }
        return false;
    }
    else if(inputNumber < arr[centerPoint])         // if inputNumber < value of center point then assign _right = centerPoint
    {
        _right = centerPoint;
        findNumber(_left, _right, arr, inputNumber);
    }
    else                                           // if inputNumber > value of center point then assign _left = centerPoint
    {
        _left = centerPoint;
        findNumber(_left, _right, arr, inputNumber);
    }
}

int main() {
    
    uint8_t arr[SIZE];

    createArray(arr);

    sort(SIZE, arr);

     // In ra mảng
    printf("Mang ngau nhien:\n");
    for (uint8_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    uint8_t result = (uint8_t)findNumber(0, SIZE - 1, arr, 80);
    printf("result:%d\n", result);

}

