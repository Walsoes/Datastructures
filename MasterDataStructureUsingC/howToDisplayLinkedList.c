#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int main()
{
    Node *first;    
    Node *temp = first;

    while (temp != NULL)
    {
    temp = temp->next; 
        
    }

    return 0;
}