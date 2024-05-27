#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{

    int *q;
    int size;
    int rear;
    int front;
} Queue;

Queue *circularQueueInit(int n)
{
    Queue *x = (Queue *)malloc(sizeof(Queue));
    assert(x);

    x->size = n;
    x->q = (int *)malloc(x->size * sizeof(int));
    x->rear = x->front = 0;

    return x;
}

int isFull(Queue *x)
{
    if ((x->rear + 1) % x->size == x->front)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *x)
{
    if (x->front == x->rear)
        return 1;
    else
        return 0;
}

void resetQueue(Queue *x)
{
    if (x->front == x->rear)
    {
        x->front = x->rear = -1;
    }
}

void enqueue(Queue *x, int data)
{
    if (isFull(x) == 1)
    {
        printf("Queue if Full\n");
    }
    else
    {
        x->rear = (x->rear + 1) % x->size;

        x->q[x->rear] = data;
    }
}

void dequeue(Queue *x)
{
    if (isEmpty(x) == 1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x->front = (x->front + 1) % x->size;
    }
}

int first(Queue *x)
{
    if (isEmpty(x) == 1)
    {

        printf("Queue is Empty\n");
        return -1;
    }
    else
    {

        return x->q[(x->front + 1) % x->size];
    }
}

int last(Queue *x)
{
    if (isEmpty(x) == 1)
    {
        return -1;
    }
    else
    {
        return x->q[x->rear];
    }
}

int main()
{

    Queue *myLongQueue = circularQueueInit(5);

    enqueue(myLongQueue, 5);
    enqueue(myLongQueue, 10);
    enqueue(myLongQueue, 15);
    enqueue(myLongQueue, 20);

    printf("First element of queue: %d\n", first(myLongQueue));
    printf("Last element of queue: %d\n", last(myLongQueue));

    dequeue(myLongQueue);
    dequeue(myLongQueue);
    dequeue(myLongQueue);

    //   dequeue(myLongQueue);

    enqueue(myLongQueue, 15);
    enqueue(myLongQueue, 20);
    
    printf("First element of queue: %d\n", first(myLongQueue));
    printf("Last element of queue: %d\n", last(myLongQueue));

    //  resetQueue(myLongQueue);

    /*     enqueue(myLongQueue, 5);
        enqueue(myLongQueue, 10);
        enqueue(myLongQueue, 15);

        printf("First element of queue: %d\n", first(myLongQueue));
        printf("Last element of queue: %d\n", last(myLongQueue));
     */
    return 0;
}
