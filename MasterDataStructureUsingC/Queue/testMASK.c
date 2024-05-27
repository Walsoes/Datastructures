#include <stdio.h>

char pressAnyKey(char key)
{
}

int main()
{
    // Define arrays to store day names and monitor status
    const char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int dayOfWeek[7];
    int bitmask = 0;

    int mondayToFriday = 62;
    int wholeWeek = 127;
    char choose;

    printf(
        "Do you want to monitor Monday to Friday (5) or the whole week (7) or choose individual days (Press any key)?");
    choose = getchar();

    if (choose == '5')
    {
        bitmask = 62;
    }
    else if (choose == '7')
    {
        bitmask = 127;
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            printf("Enter 1 to monitor %s, or 0 to skip: ", dayNames[i]);
            scanf("%d", &dayOfWeek[i]);

            // If the user wants to monitor this day, set the corresponding bit in the bitmask
            if (dayOfWeek[i] == 1)
            {
                bitmask |= (1 << i);
            }
        }
    }

    // Display the resulting bitmask
    printf("%d\n", bitmask);

    return 0;
}