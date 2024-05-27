#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;

} Node;

void display(Node *temp)
{
    while (temp != NULL)
    {
        printf("Data: %d ", temp->data);

        temp = temp->next;
    }
    printf("\n");
}

void recursiveDisplay(Node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        recursiveDisplay(temp->next);
    }
}

int main()
{

    return 0;
}