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

int isFull(Stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }

    return 0;
}

int isEmpty(Stack *st)
{
    if (st->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack *st, int x)
{
    if (isFull(st))
    {
        printf("Stack Overflow");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

void pop(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow");
    }
    else
    {
        st->top--;
    }
}

int stackTop(Stack *st)
{
    if (isEmpty(st))
        return -1;
    else
        return st->s[st->top];
}

int peek(Stack *st, int pos)
{
    pos = st->top - pos + 1;

    if (pos < 0)
    {
        return -1;
    }

    return st->s[pos];
}

int main()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    assert(st);

    st->size = 5;
    st->s = (int *)malloc(sizeof(int) * st->size);
    st->top = -1;

    return 0;
}