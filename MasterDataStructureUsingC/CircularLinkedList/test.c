#include <stdio.h>

int main()
{
    char c;

    do
    {
        printf("enter a number");
        scanf("%c", &c);
        printf("\n");

    } while (c > '0' && c < '9');
}