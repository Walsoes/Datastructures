#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct queue
{
    struct node *front;
    struct node *rear;

} Queue;

Queue *queueLLInit()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    assert(q);

    q->front = NULL;
    q->rear = NULL;

    return q;
}

int isEmpty(Queue *q)
{
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    assert(newNode);

    if (newNode == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        if (isEmpty(q) == 1)
        {
            q->front = q->rear = newNode;
        }
        else
        {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

void dequeue(Queue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        Node *t = q->front;
        q->front = q->front->next;
        free(t);
    }
}


int first(Queue *q)
{
    if (isEmpty(q) == 1)
    {

        printf("Queue is Empty\n");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}

int last(Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    else
    {
        return q->rear->data;
    }
}

int main()
{

    Queue *q = queueLLInit();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);

    printf("First element of queue: %d\n", first(q));
    printf("Last element of queue: %d\n", last(q));

    dequeue(q);
    dequeue(q);

    printf("Last element of queue: %d\n", last(q));

    /*    int test = last(q);
        printf("HEj %d\n", test); */
    printf("First element of queue: %d\n", first(q));


    return 0;
}
