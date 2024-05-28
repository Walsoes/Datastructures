#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left, *right;
} TreeNode;

/* void checkChildren(TreeNode *temp)
{
    if (temp == NULL)
    {
        printf("The node is NULL.\n");
        return;
    }

    int rightUsed = temp->right != NULL;
    int leftUsed = temp->left != NULL;

    if (rightUsed && leftUsed)
    {
        printf("Both right and left are not NULL.\n");
    }
    else if (rightUsed)
    {
        printf("Right is not NULL, Left is NULL.\n");
    }
    else if (leftUsed)
    {
        printf("Left is not NULL, Right is NULL.\n");
    }
    else
    {
        printf("Both right and left are NULL.\n");
    }
} */

TreeNode *binarySearchTreeConstructor(int *inputData, int size)
{
    if (inputData == NULL || size <= 0)
    {
        printf("inputdata cannot be empty or size less than 0\n");
        printf("Exiting...");

        exit(EXIT_FAILURE);
    }
    else
    {
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        assert(root);

        int i = 0;
        root->data = inputData[i];
        root->left = NULL;
        root->right = NULL;

        TreeNode *temp, *parent;

        for (i = 1; i < size; i++)
        {
            temp = root;
            parent = NULL;

            // create child nodes
            TreeNode *newChildNode = (TreeNode *)malloc(sizeof(TreeNode));
            assert(newChildNode);

            newChildNode->data = inputData[i];
            newChildNode->left = NULL;
            newChildNode->right = NULL;

            while (temp != NULL)
            {
                parent = temp;
                temp = (newChildNode->data >= temp->data) ? temp->right : temp->left;
            }

            // Insert the new node
            if (newChildNode->data < parent->data)
            {
                parent->left = newChildNode;
            }
            else
            {
                parent->right = newChildNode;
            }
        }
        return root;
    }
}

void printTree(TreeNode *top)
{
    static int counter = 1;

    if (top == NULL)
    {
        return;
    }

    printf("%d  %d\n", top->data, counter);
    counter++;

    // Recursively print the left subtree
    printTree(top->left);

    // Recursively print the right subtree
    printTree(top->right);
}

int main()
{
    int inputArray[] = {89, 12, 56, 34, 80, 100, 120, 93};

    int arrSize = sizeof(inputArray) / sizeof(inputArray[0]);

    for (size_t i = 0; i < arrSize; i++)
    {
        printf(" %d", inputArray[i]);
    }
    printf("\n");

    TreeNode *top = binarySearchTreeConstructor(inputArray, arrSize);

    printTree(top);
    return 0;
}