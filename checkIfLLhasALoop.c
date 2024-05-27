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

int hasLinkedListALoop(Node *head)
{
    Node *p, *q;

    p = q = head;

    while (q != NULL)
    {

        p = p->next;
        q = q->next;

        if (q != NULL)
        {
            q = q->next;
        }

        if (p == q)
        {
            return 1;
        }
    }
    return 0;
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

void makeLoop(Node *head)
{
    Node *looper;
    int counter = 0;

    while (head->next != NULL)
    {
        counter++;

        if (counter == 3)
        {
            looper = head;
        }
        head = head->next;
    }

    head->next = looper;
}

int main()
{
    Node *linkedListWithLoop = createLinkedList();

    display(linkedListWithLoop);

    int hasLoops = hasLinkedListALoop(linkedListWithLoop);

    printf("Linked list has a loop %d\n", hasLoops);

    makeLoop(linkedListWithLoop);

    // hasLoops = hasLinkedListALoop(linkedListWithLoop);

    hasLoops = hasLoopRec(linkedListWithLoop, linkedListWithLoop->next);

    printf("Linked list has a loop %d\n", hasLoops);

    return 0;
}