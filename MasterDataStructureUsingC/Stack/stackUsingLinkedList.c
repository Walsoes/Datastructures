#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int *s;
    int size;
    int top;
} Stack;

typedef struct node
{
    int data;
    struct node *next;
} Node;

/* int isFull(Stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }

    return 0;
} */

int isEmpty(Node *top)
{
    return top == NULL ? 1 : 0;
}

void printLinkedList(Node *first)
{
    static int count = 0;
    if (first != NULL)
    {
        count++;
        printf("stack level %d: %d\n", count, first->data);
        printLinkedList(first->next);
    }
}

Node *push(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    assert(newNode);

    newNode->data = data;

    if (isEmpty(head))
    {

        newNode->next = NULL;

        printf("No nodes found, creating first node\n");

        return newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
}

Node *pop(Node *top)
{
    if (isEmpty(top) == 1)
    {
        printf("Stack Underflow\n");

        return NULL;
    }

    else
    {
        Node *temp = top;
        top = top->next;

        free(temp);

        return top;
    }
}

int stackTop(Node *top)
{
    if (isEmpty(top) == 1)
        return -1;
    else
        return top->data;
}

int peek(Node *top, int pos)
{

    for (int i = 0; top != NULL && i < pos - 1; i++)
    {
        top = top->next;
    }

    if (top == NULL)
    {
        return -1;
    }
    else
    {

        return top->data;
    }
}

int main()
{
    /*     Stack *st = (Stack *)malloc(sizeof(Stack));
        assert(st);

        st->size = 5;
        st->s = (int *)malloc(sizeof(int) * st->size);
        st->top = -1; */

    Node *myLinkedList = NULL;

    myLinkedList = push(myLinkedList, 5);
    myLinkedList = push(myLinkedList, 7);
    myLinkedList = push(myLinkedList, 8);
    myLinkedList = push(myLinkedList, 9);
    myLinkedList = push(myLinkedList, 10);
    printLinkedList(myLinkedList);

    myLinkedList = pop(myLinkedList);
    myLinkedList = pop(myLinkedList);
    myLinkedList = pop(myLinkedList);
    printf("Data in peek: %d\n", peek(myLinkedList, 2));
    printf("Data in stack top: %d\n", stackTop(myLinkedList));
    myLinkedList = pop(myLinkedList);

    myLinkedList = pop(myLinkedList);
    myLinkedList = pop(myLinkedList);

    return 0;
}