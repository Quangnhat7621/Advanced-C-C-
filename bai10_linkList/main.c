#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct node
{
    uint8_t value;
    struct node *next;
};

typedef struct node node;

node *createNode(uint8_t value)
{
    node *Node = (node *)malloc(sizeof(node));
    Node->value = value;
    Node->next = NULL;
    return Node;
}

void pushPack(node *arr, uint8_t value)
{
    node *temp, *p;
    temp = createNode(value);
    if(arr == NULL)
    {
        arr = temp;
    }
    else
    {
        p = arr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        
    }
}

int main()
{
    node *arr = NULL;
    pushPack(arr, 3);
    pushPack(arr, 4);
}