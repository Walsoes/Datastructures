#include <assert.h>
#include <limits.h>
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

int isLinkedListSortedRec(Node *current, Node *prev)
{
    if (current == NULL)
    {
        return 1;
    }

    if (current->data >= prev->data)
    {
        return isLinkedListSortedRec(current->next, current);
    }
    else
    {
        return 0;
    }
}

int RisSorted(Node *temp, int x)
{
    if (temp != NULL && temp->data >= x)
    {
        return RisSorted(temp->next, temp->data);
    }
    else
    {
        if (temp == NULL)
            return 1;
        else
            return 0;
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

int main()
{
    Node *myLinkedList = createLinkedList();

    display(myLinkedList);

    int result = isLinkedListSortedRec(myLinkedList, myLinkedList);
    int result2 = RisSorted(myLinkedList, -1);

    if (result2 == 1)
    {
        printf("The LL is sorted ascending");
    }
    else
    {
        printf("Thelinked list is not sorted");
    }

    return 0;
}