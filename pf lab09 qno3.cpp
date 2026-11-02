
#include <stdio.h>

int main()
{
    int readings[7] = {12, 15, 10, 18, 20, 14, 16};

    int *ptr = readings;
    int *linkedMeter = NULL;

    int i;
    int total = 0;
    int highest = *ptr;
    int highestDay = 1;
    int threshold;

    printf("SMART METER MEMORY INSPECTOR\n\n");

    // Display readings and addresses
    for (i = 0; i < 7; i++)
    {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
        printf("Address: %p\n", (void *)(ptr + i));

        total = total + *(ptr + i);

        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
            highestDay = i + 1;
        }
    }

    // Address difference
    printf("\nAddress difference between consecutive readings:\n");

    for (i = 0; i < 6; i++)
    {
        printf("%td bytes\n",
               (char *)(ptr + i + 1) - (char *)(ptr + i));
    }

    printf("\nWeekly total: %d\n", total);
    printf("Highest consumption: %d\n", highest);
    printf("Highest consumption day: %d\n", highestDay);

    // Peak tariff adjustment
    printf("\nEnter consumption threshold: ");
    scanf("%d", &threshold);

    for (i = 0; i < 7; i++)
    {
        if (*(ptr + i) > threshold)
        {
            *(ptr + i) = *(ptr + i) * 2;
        }
    }

    printf("\nReadings after peak adjustment:\n");

    for (i = 0; i < 7; i++)
    {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
    }

    // Linked meter: unassigned case
    printf("\nLinked meter test:\n");

    if (linkedMeter == NULL)
    {
        printf("Linked meter is not assigned.\n");
    }
    else
    {
        printf("Linked meter reading: %d\n", *linkedMeter);
    }

    // Assign linked meter to the fourth reading
    linkedMeter = ptr + 3;

    if (linkedMeter != NULL)
    {
        printf("Linked meter is now assigned.\n");
        printf("Reading: %d\n", *linkedMeter);
    }

    return 0;
}

