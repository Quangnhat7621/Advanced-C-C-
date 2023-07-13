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

void pushPack(node **arr, uint8_t value)
{
    node *temp, *p;
    temp = createNode(value);
    if(*arr == NULL)
    {
        *arr = temp;
    }
    else
    {
        p = *arr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        
    }
}

typedef struct
{
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
}CenterPoint;

CenterPoint *buildTree(node *head, int start, int end)
{
    if(head == NULL && start > end)
    {
        return NULL;
    }

    int mid = (end + start)/2;
    node *Node = head;
    for (int i = start; i < mid; i++)
    {
        if (Node->next == NULL)
        {
            break;
        }
        Node = Node->next;
        
    }

    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    
};

CenterPoint *centerPoint(node *head)
{
    int length = 0;
    node *Node = head;
    while (Node != NULL)
    {
        Node = Node->next;
        length++;
    }
    
}
int main()
{
    node *arr = NULL;
    printf("diachi: %p\n", arr);
    pushPack(&arr, 3);
    pushPack(&arr, 4);
    pushPack(&arr, 10);
    pushPack(&arr, 123);
}