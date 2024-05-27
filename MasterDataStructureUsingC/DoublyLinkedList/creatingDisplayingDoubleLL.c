#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct doubleNode
{
    struct doubleNode *prev;
    int data;
    struct doubleNode *next;

} DoubleNode;

void printDoubleLinkedList(DoubleNode *first, bool forward)
{
    DoubleNode *temp = first;

    int i, counter;
    i = counter = 0;

    if (forward == true)
    {
        do
        {
            printf("Data of Node %d: %d\n", i + 1, temp->data);

            temp = temp->next;
            i++;
        } while (temp != NULL);
    }
    else if (forward == false)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            counter++;
        }

        do
        {
            printf("Data of Node %d backwards: %d\n", counter + 1, temp->data);
            temp = temp->prev;
            counter--;
        } while (temp != NULL);
    }
}

DoubleNode *deleteNodeInDoubleLL(DoubleNode *first, int pos)
{
    DoubleNode *temp, *prev;
    temp = first;
    prev = NULL;
    int counter = 1;

    if (pos == 0)
    {
        temp = temp->next;

        temp->prev = NULL;
        first->next = NULL;
        free(first);
        first = NULL;
        return temp;
    }

    while (counter != pos)
    {
        counter++;
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
    temp = NULL;
    return first;
}

DoubleNode *createDoubleLinkedList()
{
    DoubleNode *first, *last, *prev;

    int i, data, numberOfNodes;

    printf("How many nodes do you want to create?");
    scanf("%d", &numberOfNodes);

    if (numberOfNodes == 0)
    {
        printf("Have to be greater than 0.\n");

        first = last = NULL;

        exit(EXIT_FAILURE);
    }
    else
    {

        for (i = 0; i < numberOfNodes; i++)
        {
            DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
            assert(newNode);

            printf("Enter data in node %d: ", i + 1);
            scanf("%d", &data);

            newNode->data = data;

            if (i == 0)
            {
                newNode->next = NULL;
                newNode->prev = NULL;
                first = newNode;
                last = first;
            }
            else
            {
                last->next = newNode;
                newNode->prev = last;
                newNode->next = NULL;
                last = newNode;
            }
        }

        return first;

        /* code */
    }
}

int main()
{
    DoubleNode *doubleLinkedList = createDoubleLinkedList();

    printDoubleLinkedList(doubleLinkedList, true);

    doubleLinkedList = deleteNodeInDoubleLL(doubleLinkedList, 4);

    printDoubleLinkedList(doubleLinkedList, true);

    return 0;
}