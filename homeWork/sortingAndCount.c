#include<stdio.h>
#include<stdint.h>

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

// count the number of appearing prequency
void frequency(uint8_t arr_len, uint8_t _arr[])
{
    uint8_t number[100];
    uint8_t freg[100];
    uint8_t count = 1;
    uint8_t index = 0;
    for(uint8_t i = 0; i < arr_len - 1; i++)
    {
       if(_arr[i] == _arr[i+1])
       {
            if((i + 1) == (arr_len - 1))
            {
                count++;
                number[index] = _arr[i];
                freg[index] = count;
            }
            else
            {
                count++;
            }
       }
       else if( _arr[i] != _arr[i + 1])
       {
            if((i + 1) != (arr_len -1))
            {
                number[index] = _arr[i];
                freg[index] = count;
                index++;
                count = 1;
            }
            else
            {
                number[index] = _arr[i];
                freg[index] = count;
                index++;
                count = 1;
                number[index] = _arr[i + 1];
                freg[index] = count;
            }
       }
    }
    for(uint8_t i = 0; i <= index; i++)
    {
        printf("number: %d \t frequency: %d\n", number[i], freg[i]);
    }


}

void main()
{
// create an array
uint8_t arr[] = {1, 5, 8, 6, 2, 5, 7, 5, 8, 1, 2, 6, 10, 12};

// array length
uint8_t lengthOfArray = 14; 

// sorting array
sort(lengthOfArray, arr);   

// print array after sorting
for(uint8_t i = 0; i < lengthOfArray; i++)
    {
        printf("%d \t", arr[i]);
    }
printf("\n");

// count appeared frequencies
frequency(lengthOfArray, arr);

}

