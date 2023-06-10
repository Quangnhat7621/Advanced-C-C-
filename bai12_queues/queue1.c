#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

#define size 5


typedef struct
{
    int8_t front;
    int8_t rear;
    uint8_t arr[size];
}Queue;

// initialing queue value
void QueueInit(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// This operation indicates whether the queue is empty or not.
bool isEmpty(Queue queue)
{
    if(
        ((queue.front == -1) && (queue.rear == - 1))                // just initial queue
        ||
        ((queue.front == size -1) && (queue.rear == size - 1))      // after taking out all values of queue
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

// This operation indicates whether the queue is full or not.
bool isFull(Queue queue)
{
    if((queue.rear == -1) && (queue.front == size - 1))         // the queue is full when rear = front = size -1
    {
        return true;
    }
    else
    {
        return false;
    }
}

// This operation returns the element at the front end without removing it.
uint8_t front(Queue *queue)
{
    return queue->arr[queue->front];
}

// This operation returns the element at the rear end without removing it.
uint8_t rear(Queue *queue)
{
    return queue->arr[queue->rear];
}


//This operation returns the size of the queue i.e. the total number of elements it contains.  
uint8_t Queue_size(Queue queue)
{
    return (queue.front - queue.rear);
}

// Inserts an element at the end of the queue i.e. at the rear end.
void enqueu(Queue *queue, uint8_t value)
{
    if(isFull(*queue))
    {
        printf("queue is full \n");
    }
    else
    {
        queue->arr[++(queue->front)] = value; 
    }
    
    
}

// This operation removes and returns an element that is at the front end of the queue.
uint8_t dequeue(Queue *queue)
{
    if(isEmpty(*queue))
    {
        printf("queue is empty\n");
    }
    else
    {
        queue->rear ++;         //add rear by 1
        uint8_t temp = queue->arr[queue->front]; // create a temporary and store element at the end of the queue
        for(uint8_t i = 0; i < size - 1; i ++)
        {
            queue->arr[queue->front - i] = queue->arr[queue->front - i - 1];    // arr[n] = arr[n - 1]
        }
        queue->arr[0] = '\0';   // after shifting value, assign the '\0' into the firt element of the queue
        return temp;
    }
    
}




int main()
{
    // define queue
    Queue queue;

    //initialing queue
    QueueInit(&queue);

    // there are no values in queue
    printf("empty: %d\n", (uint8_t)isEmpty(queue));         // 1 : true, 0: false
    
    
    printf("front: %d\n", queue.front);
    // add first element
    enqueu(&queue, 1);
    printf("front: %d\n", queue.front);

    // add second element
    enqueu(&queue, 2);
    printf("front: %d\n", queue.front);

    // add third element
    enqueu(&queue, 5);
    printf("front: %d\n", queue.front);

    // add fourth element
    enqueu(&queue, 3);
    printf("front: %d\n", queue.front);

    // add fifth element
    enqueu(&queue, 4);
    printf("front: %d\n", queue.front);   

    // the queue is full now, but we will try to add one and see the result
    enqueu(&queue, 5);  // actualy the queue is full, so output is "queue is full"  and value cannot add sixth value
    printf("front: %d\n", queue.front);

    // print the number of elements in queue
    printf("size: %d\n", Queue_size(queue));

    // take out value of queue one by one
    printf("output: %d\n", dequeue(&queue));
    printf("output: %d\n", dequeue(&queue));
    printf("output: %d\n", dequeue(&queue));
    printf("output: %d\n", dequeue(&queue));
    printf("output: %d\n", dequeue(&queue));

    // the queue is empty after removing 5 element, but we try to delete one and observe the result
    printf("output: %d\n", dequeue(&queue));

    // there are no doubts, the output is "queue is empty"

}