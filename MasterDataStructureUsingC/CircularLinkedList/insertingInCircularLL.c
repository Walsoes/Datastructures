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
    printf("\n");
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

        first = last = NULL;

        exit(EXIT_FAILURE);
    }
    else
    {

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

        /* code */
    }
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

int hasLoopRec(Node *p, Node *q)
{
    if (q == NULL)
    {
        return 0; /* code */
    }

    if (q->next != NULL)
    {
        q = q->next;

        if (p == q)
        {
            return 1;
        }

        return hasLoopRec(p->next, q->next);
    }

    return 0;
}

int countNodesRec(Node *head, Node *temp, int count)
{

    if (head == temp->next)
    {
        return count + 1;
    }
    else
    {
        return countNodesRec(head, temp->next, count + 1);
    }
}

Node *insertingInCircularLL(Node *head, int pos, int data, int numOfNodes)
{

    if (pos <= numOfNodes)
    {
        int counter = 1;
        Node *newNode, *temp;
        newNode = (Node *)malloc(sizeof(Node));
        assert(newNode);

        temp = head;

        if (pos == 0)
        {

            newNode->data = head->data;
            newNode->next = head->next;

            head->data = data;
            head->next = newNode;

            return head;
        }

        while (counter != pos)
        {
            temp = temp->next;
            counter++;
        }

        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
    else
    {
        printf("List to short, nothing happends. numOfNodes too large");

        return head;
    }
}

int main()
{
    Node *myLinkedList = createLinkedList();

    display(myLinkedList);

    makeCircular(myLinkedList);

    displayCircular(myLinkedList);

    int numOfNodes = countNodesRec(myLinkedList, myLinkedList, 0);

    myLinkedList = insertingInCircularLL(myLinkedList, 5, 5, numOfNodes);

    displayCircular(myLinkedList);

    int hasLoop = hasLoopRec(myLinkedList, myLinkedList->next);

    printf("LL has a loop: %d", hasLoop);

    // displayCircularRec(myLinkedList, myLinkedList);

    return 0;
}