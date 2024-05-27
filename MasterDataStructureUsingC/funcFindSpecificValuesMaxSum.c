#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int smallestPrimeFactor(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return i; // Found the smallest prime factor
        }
    }
    return n; // n is prime
}

int *findMaxSumOfArrayElements(const int *sourceArray, int size)
{
    for (int j = 0; j < size; j++)
    {
        if (sourceArray[j] > size)
        {
            printf("ArrayElement out of range\n");
            exit(1);
        }
    }

    int *tempArr;
    int i;
    tempArr = (int *)calloc(size + 1, sizeof(int));
    assert(tempArr);

    for (i = 0; i < size; i++)
    {
        ++tempArr[sourceArray[i]];
    }

    for (i = 1; i <= size; i++)
    {
        tempArr[i] = i * tempArr[i];
    }

    int MaxSum = tempArr[0];

    int S = (size * (size + 1)) / 2;
    
    int *flag = (int *)malloc(smallestPrimeFactor(S) * sizeof(int));
    assert(flag);

    int k = 0;

    for (i = 1; i <= size; i++)
    {
        if (MaxSum <= tempArr[i])
        {
            MaxSum = tempArr[i];

            flag[k] = i;
            k++;
        }
    }
    free(tempArr);

    return flag;
    free(flag);
}

int main()
{
    const unsigned int sourceArr[SIZE] = {1, 1, 1, 3, 2};

    int *result = findMaxSumOfArrayElements(sourceArr, SIZE);

    int resultSize = sizeof(result) / sizeof(int);

    for (unsigned int i = 0; i <= resultSize; i++)
    {
        printf("The sum of arrayvalues are greatest with: %d\n", result[i]);
    }

    return 0;
}
