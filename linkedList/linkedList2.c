#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Insert(Node **head, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Failed to allocate memory\n");

        exit(EXIT_FAILURE);
    }
    temp->data = x;
    temp->next = NULL;

    if (*head == NULL)
    {
        // If the list is empty, make the new node the head
        *head = temp;
    }
    else
    {
        // Otherwise, traverse to the end and add the new node
        Node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }
}

void Print(Node *head)
{
    Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);

        temp = temp->next;
    }
    printf("\n");
}

void freeLinkedList(Node **head)
{
    if (*head == NULL)
    {
        // If the list is empty, make the new node the head
        return;
    }
    else
    {
        // Otherwise, traverse to the end and add the new node
        Node *temp = *head;
        Node *nextadress;
        while (temp != NULL)
        {
            nextadress = temp->next;
            free(temp);
            temp = nextadress;
        }
        
        *head = NULL;
    }
}

int main()
{
    Node *head = NULL; // Initialize an empty linked list

    printf("How many numbers?\n");
    int n, i, x;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number:");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }

    freeLinkedList(&head);

    Print(head);

    return 0;
}
