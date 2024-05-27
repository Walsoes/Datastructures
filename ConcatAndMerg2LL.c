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

Node *concatTwoLL(Node *head, Node *head2)
{
    Node *first, *last;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = head->data;
    newNode->next = NULL;
    first = newNode;
    last = first;

    head = head->next;

    while (head != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        assert(newNode);

        newNode->data = head->data;

        last->next = newNode;
        newNode->next = NULL;
        last = newNode;

        head = head->next;
    }

    last->next = head2;

    return first;
}

void concatenation(Node *first, Node *second)
{
    Node *temp = first;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = second;
}

Node *mergeSortedLinkedList(Node *first, Node *second)
{
    Node *third, *last;

    if (first->data <= second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first != NULL && second != NULL)
    {
        /* code */
        if (first->data <= second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }

    return third;
}

int main()
{
    Node *myLinkedList = createLinkedList();
    display(myLinkedList);
    Node *myLinkedList2 = createLinkedList();

    display(myLinkedList2);

    // concatenation(myLinkedList, myLinkedList2);

    //   Node *conCat = concatTwoLL(myLinkedList, myLinkedList2);
    Node *merged = mergeSortedLinkedList(myLinkedList, myLinkedList2);

    //  display(conCat);

    display(merged);

    return 0;
}