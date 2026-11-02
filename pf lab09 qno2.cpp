
#include <stdio.h>

// Function declarations
int calculateTotal(int marks[], int size);
float calculateAverage(int total, int size);
int findHighest(int marks[], int size);
int findLowest(int marks[], int size);
int countPassed(int marks[], int size, int threshold);
int countTopScorers(int marks[], int size);
void applyBonus(int marks[], int size, int bonus);
void displayReport(int marks[], int size, int threshold);

int main()
{
    int marks[10];
    int threshold, bonus;
    int i;

    // Input marks
    for (i = 0; i < 10; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);

        while (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid marks! Enter marks between 0 and 100: ");
            scanf("%d", &marks[i]);
        }
    }

    printf("\nEnter passing threshold: ");
    scanf("%d", &threshold);

    while (threshold < 0 || threshold > 100)
    {
        printf("Enter threshold between 0 and 100: ");
        scanf("%d", &threshold);
    }

    // First analysis
    printf("\n========== ORIGINAL RESULT ==========\n");
    displayReport(marks, 10, threshold);

    // Input bonus
    printf("\nEnter bonus marks: ");
    scanf("%d", &bonus);

    while (bonus < 0)
    {
        printf("Bonus cannot be negative. Enter again: ");
        scanf("%d", &bonus);
    }

    // Apply bonus
    applyBonus(marks, 10, bonus);

    // Second analysis
    printf("\n========== MODERATED RESULT ==========\n");
    displayReport(marks, 10, threshold);

    return 0;
}

// Calculate total marks
int calculateTotal(int marks[], int size)
{
    int total = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        total = total + marks[i];
    }

    return total;
}

// Calculate average marks
float calculateAverage(int total, int size)
{
    return (float)total / size;
}

// Find highest marks
int findHighest(int marks[], int size)
{
    int highest = marks[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

// Find lowest marks
int findLowest(int marks[], int size)
{
    int lowest = marks[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

// Count passed students
int countPassed(int marks[], int size, int threshold)
{
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (marks[i] >= threshold)
        {
            count++;
        }
    }

    return count;
}

// Count students having highest marks
int countTopScorers(int marks[], int size)
{
    int highest = findHighest(marks, size);
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (marks[i] == highest)
        {
            count++;
        }
    }

    return count;
}

// Apply bonus without exceeding 100
void applyBonus(int marks[], int size, int bonus)
{
    int i;

    for (i = 0; i < size; i++)
    {
        marks[i] = marks[i] + bonus;

        if (marks[i] > 100)
        {
            marks[i] = 100;
        }
    }
}

// Display complete analysis
void displayReport(int marks[], int size, int threshold)
{
    int total;
    int highest;
    int lowest;
    int passed;
    int topScorers;
    float average;

    total = calculateTotal(marks, size);
    average = calculateAverage(total, size);
    highest = findHighest(marks, size);
    lowest = findLowest(marks, size);
    passed = countPassed(marks, size, threshold);
    topScorers = countTopScorers(marks, size);

    printf("\nTotal Marks: %d\n", total);
    printf("Average Marks: %.2f\n", average);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Passed Students: %d\n", passed);
    printf("Students Sharing Highest Marks: %d\n", topScorers);
}

