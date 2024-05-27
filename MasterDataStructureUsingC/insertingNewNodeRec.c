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

Node *insertingNewNodeRec(Node *first, Node *p, int insertPoint, int data)
{
    static int currentPos = 0;

    if (currentPos < insertPoint - 1)
    {
        currentPos++;
        insertingNewNodeRec(first, p->next, insertPoint, data);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));

        newNode->data = data;
        if (insertPoint == 0)
        {
            newNode->next = first;
            first = newNode;
        }
        else
        {

            newNode->next = p->next;
            p->next = newNode;

            /* code */
        }
        return first;
    }
}

void createLinkedList()
{
    Node *first, *last;
    first = (Node *)malloc(sizeof(Node));
    assert(first);

    int num;
    printf("what number do you want to store?");
    scanf("%d", &num);
    first->data = num;
    last = first;
    last->next = NULL;

    printf("what number do you want to store? To stop print '-1'");
    scanf("%d", &num);
    while (num != -1)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        assert(temp);
        temp->data = num;
        last->next = temp;
        last = temp;
        last->next = NULL;

        printf("what number do you want to store? To stop print '-1'");
        scanf("%d", &num);
    }

    display(first);

    insertingNewNodeRec(first, first, 2, 3);
    display(first);
}

int main()
{
    createLinkedList();

    return 0;
}
