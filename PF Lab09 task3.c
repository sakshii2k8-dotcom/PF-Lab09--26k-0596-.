#include <stdio.h>

int calculateTotal(int marks[], int size);
double calculateAverage(int total, int size);
int findHighest(int marks[], int size);
int findLowest(int marks[], int size);
int countPassed(int marks[], int size, int threshold);
int countTopScorers(int marks[], int size);
void applyBonus(int marks[], int size, int bonus);
void displayReport(int marks[], int size, int threshold);

int main() {
    int marks[10];
    int i, bonus, threshold;
    int total;
    double average;

    for (i = 0; i < 10; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);

        while (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Enter marks between 0 and 100: ");
            scanf("%d", &marks[i]);
        }
    }

    printf("\nEnter pass threshold: ");
    scanf("%d", &threshold);

    while (threshold < 0 || threshold > 100) {
        printf("Enter a threshold between 0 and 100: ");
        scanf("%d", &threshold);
    }

    printf("\n========== ORIGINAL RESULTS ==========\n");
    displayReport(marks, 10, threshold);

    printf("\nEnter bonus marks: ");
    scanf("%d", &bonus);

    while (bonus < 0) {
        printf("Bonus cannot be negative. Enter again: ");
        scanf("%d", &bonus);
    }

    applyBonus(marks, 10, bonus);

    printf("\n========== MODERATED RESULTS ==========\n");
    displayReport(marks, 10, threshold);

    return 0;
}

int calculateTotal(int marks[], int size) {
    int i, total = 0;

    for (i = 0; i < size; i++) {
        total = total + marks[i];
    }

    return total;
}

double calculateAverage(int total, int size) {
    return (double)total / size;
}

int findHighest(int marks[], int size) {
    int i, highest = marks[0];

    for (i = 1; i < size; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }

    return highest;
}

int findLowest(int marks[], int size) {
    int i, lowest = marks[0];

    for (i = 1; i < size; i++) {
        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }

    return lowest;
}

int countPassed(int marks[], int size, int threshold) {
    int i, count = 0;

    for (i = 0; i < size; i++) {
        if (marks[i] >= threshold) {
            count++;
        }
    }

    return count;
}

int countTopScorers(int marks[], int size) {
    int i, highest, count = 0;

    highest = findHighest(marks, size);

    for (i = 0; i < size; i++) {
        if (marks[i] == highest) {
            count++;
        }
    }

    return count;
}

void applyBonus(int marks[], int size, int bonus) {
    int i;

    for (i = 0; i < size; i++) {
        marks[i] = marks[i] + bonus;

        if (marks[i] > 100) {
            marks[i] = 100;
        }
    }
}

void displayReport(int marks[], int size, int threshold) {
    int total, highest, lowest, passed, topScorers;
    double average;

    total = calculateTotal(marks, size);
    average = calculateAverage(total, size);
    highest = findHighest(marks, size);
    lowest = findLowest(marks, size);
    passed = countPassed(marks, size, threshold);
    topScorers = countTopScorers(marks, size);

    printf("\nClass Total: %d", total);
    printf("\nClass Average: %.2f", average);
    printf("\nHighest Marks: %d", highest);
    printf("\nLowest Marks: %d", lowest);
    printf("\nStudents Passed: %d", passed);
    printf("\nStudents Sharing Top Marks: %d\n", topScorers);
}
