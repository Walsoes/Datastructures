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
        printf("%d ", temp->data);

        temp = temp->next;
    }
    printf("\n");
}

void displayCircular(Node *temp)
{
    Node *first = temp;

    do
    {
        printf("%d ", temp->data);

        temp = temp->next;
    } while (temp != first);
}

void displayCircularRec(Node *first, Node *temp)
{
    if (temp->next != first)
    {
        printf("%d ", temp->data);

       displayCircularRec(first, temp->next);
    }
    else
    {
        printf("%d ", temp->data);
    }
}

Node *createLinkedList()
{
    Node *first, *last;

    int i, data, numberOfNodes;

    printf("How many nodes do you want to create?");
    scanf("%d", &numberOfNodes);

    if (numberOfNodes == 0)
    {
        printf("Have to be greater than 0.\n");

        return NULL;
    }

    for (i = 0; i < numberOfNodes; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        assert(newNode);

        printf("Enter data in node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;

        if (i == 0)
        {
            newNode->next = NULL;
            first = newNode;
            last = first;
        }
        else
        {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
    }

    return first;
}

void makeCircular(Node *first)
{
    Node *temp = first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = first;
}

int main()
{
    Node *myLinkedList = createLinkedList();

    display(myLinkedList);

    makeCircular(myLinkedList);

    displayCircular(myLinkedList);

    displayCircularRec(myLinkedList, myLinkedList);

    return 0;
}