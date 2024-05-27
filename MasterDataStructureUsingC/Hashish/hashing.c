#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left, *right;
} TreeNode;

void checkChildren(TreeNode *temp)
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
}

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

        TreeNode *temp;

        for (i = 1; i < size; i++)
        {
            temp = root;

            // create first child node
            if (root->left == NULL && root->right == NULL)
            {

                TreeNode *firstChildNode = (TreeNode *)malloc(sizeof(TreeNode));

                assert(firstChildNode);

                firstChildNode->data = inputData[i];
                firstChildNode->left = NULL;
                firstChildNode->right = NULL;

                if (firstChildNode->data >= root->data)
                {
                    root->right = firstChildNode;
                }
                else
                {
                    root->left = firstChildNode;
                }
            }
            else
            {
                TreeNode *newChildNode = (TreeNode *)malloc(sizeof(TreeNode));
                assert(newChildNode);

                newChildNode->data = inputData[i];
                newChildNode->left = NULL;
                newChildNode->right = NULL;

                if (newChildNode->data >= root->data)
                {
                    temp = temp->right;
                    do
                    {
                        if (newChildNode->data >= temp->data)
                        {
                            temp->right = newChildNode;
                            break;
                        }
                        else
                        {
                            temp->left = newChildNode;
                            break;
                        }

                    } while (temp->right != NULL || temp->left != NULL);
                }
                else
                {
                    do
                    {
                        temp = temp->left;

                        if (newChildNode->data >= temp->data)
                        {
                            temp->right = newChildNode;
                            break;
                        }
                        else
                        {
                            temp->left = newChildNode;
                            break;
                        }

                    } while (temp->right != NULL || temp->left != NULL);
                }
            }
        }

        return root;
    }
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

    return 0;
}