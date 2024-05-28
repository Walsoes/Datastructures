#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left, *right;
} TreeNode;

typedef struct queueNode
{
    struct treeNode *head;

} QueueNode;

typedef struct queue
{
    struct queueNode *array;
    int size;
    int front;
    int rear;
    double level;
} Queue;

TreeNode *newNode(int data)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    assert(temp);

    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;

    return temp;
}

TreeNode *insertNode(TreeNode *root, int x)
{

    if (root == NULL)
    {
        return newNode(x);
    }
    else
    {
        while (1)
        {
            if (x > root->data && root->right != NULL)
            {
                root = root->right;
            }
            else if (x > root->data)
            {
                root->right = newNode(x);
                break;
            }
            else if (x < root->data && root->left != NULL)
            {
                root = root->left;
            }
            else if (x < root->data)
            {
                root->left = newNode(x);
                break;
            }
        }
        return NULL;
    }
}

TreeNode *RinsertNode(TreeNode *root, int x)
{
    if (root == NULL)
        return newNode(x);
    else if (x > root->data)
    {
        root->right = RinsertNode(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = RinsertNode(root->left, x);
    }
    return root;
}

Queue *createQueue(int n)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    assert(q);
    q->array = (QueueNode *)malloc(n * sizeof(QueueNode));
    q->size = n;
    q->front = q->rear = 0;
    q->level = log2(q->size);

    return q;
}

void enQueue(Queue *q, TreeNode *temp)
{
    if (q->rear == q->size)
    {
        printf("Queue is Full\n");
        return;
    }
    else
    {
        q->array[q->rear].head = temp;
        q->rear++;
    }
}

int isEmpty(Queue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}

TreeNode *deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    else
        return q->array[q->front++].head;
}

void levelOrder(TreeNode *root, int size)
{
    Queue *q = createQueue(size);
    assert(q);

    enQueue(q, root);

    while (!isEmpty(q))
    {

        TreeNode *temp = deQueue(q);

        if (temp->left != NULL)
            enQueue(q, temp->left);
        if (temp->right != NULL)
            enQueue(q, temp->right);

        printf("%d ", temp->data);
    }
    printf("\n");
}

void inOrder(TreeNode *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrderTravel(TreeNode *root)
{
}

int main()
{
    TreeNode *root = NULL;
    root = RinsertNode(root, 89);
    RinsertNode(root, 12);
    RinsertNode(root, 56);
    RinsertNode(root, 34);
    RinsertNode(root, 80);
    RinsertNode(root, 100);
    RinsertNode(root, 120);
    RinsertNode(root, 93);

    inOrder(root);

    printf("\n");

    preOrder(root);

    printf("\n");

    postOrder(root);

    printf("\n");
    levelOrder(root, 8);

    return 0;
}