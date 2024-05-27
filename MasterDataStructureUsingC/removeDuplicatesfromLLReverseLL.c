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

void *removeDuplicates(Node *p, Node *q)
{

    if (q != NULL)
    {

        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            return removeDuplicates(p, p->next);
        }
        else
        {
            return removeDuplicates(p->next, q->next);
        }
    }
}

void removeDuplicates2(Node *p, Node *q)
{

    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}



void reverseElements(Node *head)
{

    int counter = 0;
    int i = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }

    int arr[counter];

    temp = head;

    while (temp != NULL)
    {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }

    temp = head;
    i--;

    while (temp != NULL)
    {
        temp->data = arr[i];
        temp = temp->next;
        i--;
    }

    /*  for (int i = 0; i < counter; i++)
     {
         printf("%d" , arr[i]);
     } */
}

Node *RreverseList(Node *p, Node *q)
{
    // Base case: when q reaches the end of the list
    if (q == NULL)
    {
        // Return p which is the new head of the reversed list
        return p;
    }

    // Recursive call to traverse to the end of the list
    Node *new_head = RreverseList(q, q->next);

    // Reverse the link between current node (q) and its next node (p)
    q->next = p;

    // Set the next pointer of the original head (p) to NULL
    if (p != NULL)
    {
        p->next = NULL;
    }

    // Return the new head of the reversed list
    return new_head;
}

Node *reverseLinks(Node *first)
{
    Node *p, *q, *r;

    p = first;
    q = r = NULL;

    while (p != NULL)
    {

        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    first = q;

    return first;
}

int main()
{
    Node *myLinkedList = createLinkedList();

    display(myLinkedList);

    Node *myReversedLL = RreverseList(NULL, myLinkedList);

    display(myReversedLL);

    myReversedLL = reverseLinks(myReversedLL);

    display(myReversedLL);

    // removeDuplicates2(myLinkedList, myLinkedList->next);

    // removeDuplicates(myLinkedList, myLinkedList->next);

    /*    int result = isLinkedListSortedRec(myLinkedList, myLinkedList);a


       int result2 = RisSorted(myLinkedList, -1);

       if (result2 == 1)
       {
           printf("The LL is sorted ascending");
       }
       else
       {
           printf("Thelinked list is not sorted");
       } */

    return 0;
}