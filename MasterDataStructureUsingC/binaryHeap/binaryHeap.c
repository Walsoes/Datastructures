#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

typedef struct binaryHeap
{
    int *heap;
    int size;
    int length;

} BinaryHeap;

int isEmpty(BinaryHeap *x)
{
    if (x->length == 0)
        return 1;
    return 0;
}

/* void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} */

void swap(int *a, int *b)
{

    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *b ^ *a;
}

BinaryHeap *binaryHeap(int size)
{

    BinaryHeap *top = (BinaryHeap *)malloc(sizeof(BinaryHeap));
    assert(top);

    top->size = size;
    top->heap = (int *)malloc(top->size * sizeof(int));
    assert(top->heap);
    top->length = 0;

    return top;
}

void *sortArr(int *arr, unsigned int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] <= arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void insert(BinaryHeap *x, int data)
{
    if (x->size >= x->length + 1)
    {
        int i = x->length;
        int k = (i - 1) / 2;
        x->heap[i] = data;

        while (i != 0)
        {
            if (x->heap[i] > x->heap[k])
            {
                swap(&x->heap[i], &x->heap[k]);

                i = k;

                k = (i - 1) / 2;
            }
            else
            {
                break;
            }
        }
        x->length++;
    }
    else
    {
        printf("Not enough space in the heap\n");
        return;
    }
}

int extractMax(BinaryHeap *x)
{
    if (isEmpty(x) == 1)
    {
        return -1;
    }

    int top = x->heap[0];

    int i = 0;

    while (2 * i + 1 < x->length)
    {

        if ((2 * i + 1) < x->length && (2 * i + 2) < x->length)
        {
            int k = x->heap[2 * i + 1] > x->heap[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;

            if (x->heap[i] > x->heap[k])
            {
                swap(&x->heap[i], &x->heap[k]);

                i = k;
            }
            else
            {

                break;
            }
        }
        else if (2 * i + 1 < x->length)
        {
            int k = 2 * i + 1;

            if (x->heap[i] > x->heap[k])
            {
                swap(&x->heap[i], &x->heap[k]);

                i = k;
            }
            else
            {

                break;
            }
        }
        else
        {

            break;
        }
    }
    x->length--;

    return top;
}

int findMax(BinaryHeap *x)
{
    if (isEmpty(x) == 1)
        return -1;
    return x->heap[0];
}

int findMin(BinaryHeap *x)
{

    for (size_t i = 0; i < x->length; i++)
    {
    }
}

// Function to calculate the height of the binary heap
int calculateHeight(int heapSize)
{
    return (int)log2(heapSize + 1) - 1;
}

// Function to print the binary heap with formatting
void printHeap(BinaryHeap *n)
{
    if (n->length <= 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Binary Heap:\n");

    // Calculate the height of the binary heap
    int height = calculateHeight(n->size);

    printf("Bottom length: %d\n", (height + 1) * 2);

    int maxBottomPadding = (height + 1) * 2 * n->size;

    char format[maxBottomPadding];

    // Loop through each level of the binary heap
    for (int level = 0; level <= height; level++)
    {
        // Calculate the number of nodes at this level
        int nodesAtLevel = (int)pow(2, level);

        int nodesAtLevel2 = (int)log2(n->size - nodesAtLevel);

        printf("Data: %d", nodesAtLevel2);

        // Calculate the index of the first node at this level
        int firstNodeIndex = (int)pow(2, level) - 1;

        // Loop through the nodes at this level and print them
        for (int i = 0; i < nodesAtLevel && firstNodeIndex + i < n->length; i++)
        {

            if (nodesAtLevel == 1)
            {
                sprintf(format, "%%%dd", n->size * 2);

                printf(format, n->heap[firstNodeIndex]);
            }
            else
            {
                sprintf(format, "%%%dd", n->size / 2 - nodesAtLevel);

                printf(format, n->heap[firstNodeIndex + i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    BinaryHeap *heap;
    int size, length;

    int staticArr[SIZE] = {23, 12, 19, 35, 33, 42, 25};

    heap = binaryHeap(SIZE);

    for (size_t i = 0; i < SIZE; i++)
    {
        insert(heap, staticArr[i]);
        /* code */
    }

    //   deleteMax(heap);

    printHeap(heap);

    return 0;
}
