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

int isFull(Queue *x)
{
    if (x->rear == x->size - 1)
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
        x->q[++x->rear] = data;
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
        x->front++;
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
        return x->q[x->front + 1];
    }
}

int last(Queue *x)
{
    if (isEmpty(x))
    {
        return -1;
    }
    else
    {
        return x->q[x->rear];
    }
}

Queue *queueInit(int n)
{
    Queue *x = (Queue *)malloc(sizeof(Queue));
    assert(x);

    x->size = n;
    x->q = (int *)malloc(x->size * sizeof(int));
    x->rear = x->front = -1;

    return x;
}

int main()
{

    Queue *myLongQueue = queueInit(10);

    int test = last(myLongQueue);
    printf("HEj %d\n", test);

    enqueue(myLongQueue, 5);
    enqueue(myLongQueue, 10);
    enqueue(myLongQueue, 15);

    printf("First element of queue: %d\n", first(myLongQueue));
    printf("Last element of queue: %d\n", last(myLongQueue));

    dequeue(myLongQueue);
    dequeue(myLongQueue);
    dequeue(myLongQueue);

    printf("First element of queue: %d\n", first(myLongQueue));

    resetQueue(myLongQueue);

    enqueue(myLongQueue, 5);
    enqueue(myLongQueue, 10);
    enqueue(myLongQueue, 15);

       printf("First element of queue: %d\n", first(myLongQueue));
    printf("Last element of queue: %d\n", last(myLongQueue));


    printf("Front: %d | Rear: %d\n", myLongQueue->front, myLongQueue->rear);

    return 0;
}
