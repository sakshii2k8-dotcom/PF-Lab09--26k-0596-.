#include <stdio.h>

void wrongSwap(int a, int b);
void repairCounters(int *a, int *b);
void analyzeOccupancy(int figures[], int size, int *total, int *highest, int *lowest);

int main() {
    int wardA = 40, wardB = 25;

    int x = 60, y = 30;

    int occupancy[7] = {20, 35, 40, 25, 50, 30, 45};

    int total, highest, lowest;

    printf("========== ORIGINAL WARD COUNTERS ==========\n");

    printf("Before repair:\n");
    printf("Ward A: %d | Address: %p\n", wardA, (void *)&wardA);
    printf("Ward B: %d | Address: %p\n", wardB, (void *)&wardB);

    repairCounters(&wardA, &wardB);

    printf("\nAfter repair:\n");
    printf("Ward A: %d | Address: %p\n", wardA, (void *)&wardA);
    printf("Ward B: %d | Address: %p\n", wardB, (void *)&wardB);

    printf("\n========== WRONG SWAP ATTEMPT ==========\n");

    printf("Before wrong swap:\n");
    printf("X: %d | Address: %p\n", x, (void *)&x);
    printf("Y: %d | Address: %p\n", y, (void *)&y);

    wrongSwap(x, y);

    printf("\nAfter wrong swap:\n");
    printf("X: %d | Address: %p\n", x, (void *)&x);
    printf("Y: %d | Address: %p\n", y, (void *)&y);

    printf("\n========== WEEKLY OCCUPANCY ANALYSIS ==========\n");

    analyzeOccupancy(occupancy, 7, &total, &highest, &lowest);

    printf("\nWeekly Total: %d\n", total);
    printf("Highest Occupancy: %d\n", highest);
    printf("Lowest Occupancy: %d\n", lowest);

    return 0;
}

void wrongSwap(int a, int b) {
    int temp;

    printf("\nInside wrongSwap:\n");
    printf("Address of a: %p\n", (void *)&a);
    printf("Address of b: %p\n", (void *)&b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping inside function:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
}

void repairCounters(int *a, int *b) {
    int temp;

    printf("\nInside repairCounters:\n");
    printf("Address stored in a: %p\n", (void *)a);
    printf("Address stored in b: %p\n", (void *)b);

    temp = *a;
    *a = *b;
    *b = temp;
}

void analyzeOccupancy(int figures[], int size, int *total, int *highest, int *lowest) {
    int i;

    *total = 0;
    *highest = *figures;
    *lowest = *figures;

    printf("\nInside analyzeOccupancy:\n");
    printf("Address of first array element: %p\n", (void *)figures);
    printf("Address of total variable: %p\n", (void *)total);
    printf("Address of highest variable: %p\n", (void *)highest);
    printf("Address of lowest variable: %p\n", (void *)lowest);

    for (i = 0; i < size; i++) {
        *total = *total + figures[i];

        if (figures[i] > *highest) {
            *highest = figures[i];
        }

        if (figures[i] < *lowest) {
            *lowest = figures[i];
        }
    }
}
