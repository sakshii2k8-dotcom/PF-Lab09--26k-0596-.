#include <stdio.h>

int main() {
    int readings[7] = {12, 18, 25, 10, 30, 15, 20};

    int *ptr = readings;
    int *linkedMeter = NULL;

    int threshold;
    int total = 0;
    int highest;
    int highestDay = 1;
    int i;

    printf("Daily Smart Meter Readings:\n");

    for (i = 0; i < 7; i++) {
        printf("Day %d: %d | Address: %p\n",
               i + 1, *(ptr + i), (void *)(ptr + i));

        total = total + *(ptr + i);
    }

    printf("\nAddress Difference:\n");

    for (i = 0; i < 6; i++) {
        printf("Day %d to Day %d: %td bytes\n",
               i + 1, i + 2,
               (char *)(ptr + i + 1) - (char *)(ptr + i));
    }

    highest = *ptr;

    for (i = 1; i < 7; i++) {
        if (*(ptr + i) > highest) {
            highest = *(ptr + i);
            highestDay = i + 1;
        }
    }

    printf("\nWeekly Total: %d\n", total);
    printf("Highest Consumption: %d\n", highest);
    printf("Highest Consumption Day: %d\n", highestDay);

    printf("\nEnter peak tariff threshold: ");
    scanf("%d", &threshold);

    for (i = 0; i < 7; i++) {
        if (*(ptr + i) > threshold) {
            *(ptr + i) = *(ptr + i) * 2;
        }
    }

    printf("\nReadings After Peak Tariff Adjustment:\n");

    for (i = 0; i < 7; i++) {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
    }

    printf("\nLinked Meter Pointer:\n");

    if (linkedMeter == NULL) {
        printf("Linked meter is not assigned.\n");
    }

    linkedMeter = ptr + 2;

    if (linkedMeter != NULL) {
        printf("Linked meter is assigned.\n");
        printf("Linked meter reading: %d\n", *linkedMeter);
    }

    return 0;
}
