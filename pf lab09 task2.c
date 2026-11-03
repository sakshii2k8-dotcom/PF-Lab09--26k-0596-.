#include <stdio.h>

void displayHall1(int (*ptr)[4], int rows);
int countVacantHall1(int (*ptr)[4], int rows);

void displayHall2(int *rows[], int sizes[], int rowCount);
int countVacantHall2(int *rows[], int sizes[], int rowCount);
void bookSeat(int *rows[], int sizes[], int rowCount);

int main() {
    int hall1[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 0}
    };

    int row1[3] = {1, 0, 1};
    int row2[5] = {0, 1, 0, 1, 0};
    int row3[7] = {1, 0, 0, 1, 0, 1, 0};

    int *hall2[3] = {row1, row2, row3};
    int sizes[3] = {3, 5, 7};

    printf("========== HALL 1 ==========\n");

    displayHall1(hall1, 3);

    printf("Vacant Seats in Hall 1: %d\n",
           countVacantHall1(hall1, 3));

    printf("\n========== HALL 2 ==========\n");

    displayHall2(hall2, sizes, 3);

    printf("Vacant Seats in Hall 2: %d\n",
           countVacantHall2(hall2, sizes, 3));

    bookSeat(hall2, sizes, 3);

    printf("\n========== UPDATED HALL 2 ==========\n");

    displayHall2(hall2, sizes, 3);

    printf("Vacant Seats in Hall 2: %d\n",
           countVacantHall2(hall2, sizes, 3));

    return 0;
}

void displayHall1(int (*ptr)[4], int rows) {
    int i, j;

    printf("\nSeating Chart (0 = Vacant, 1 = Booked)\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}

int countVacantHall1(int (*ptr)[4], int rows) {
    int i, j, count = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < 4; j++) {
            if (*(*(ptr + i) + j) == 0) {
                count++;
            }
        }
    }

    return count;
}

void displayHall2(int *rows[], int sizes[], int rowCount) {
    int i, j;

    printf("\nSeating Chart (0 = Vacant, 1 = Booked)\n");

    for (i = 0; i < rowCount; i++) {
        for (j = 0; j < sizes[i]; j++) {
            printf("%d ", *(rows[i] + j));
        }
        printf("\n");
    }
}

int countVacantHall2(int *rows[], int sizes[], int rowCount) {
    int i, j, count = 0;

    for (i = 0; i < rowCount; i++) {
        for (j = 0; j < sizes[i]; j++) {
            if (*(rows[i] + j) == 0) {
                count++;
            }
        }
    }

    return count;
}

void bookSeat(int *rows[], int sizes[], int rowCount) {
    int row, seat;

    printf("\n========== BOOK A SEAT ==========\n");

    printf("Enter row number (1-3): ");
    scanf("%d", &row);

    if (row < 1 || row > rowCount) {
        printf("Invalid row! This row does not exist.\n");
        return;
    }

    printf("Enter seat number (1-%d): ", sizes[row - 1]);
    scanf("%d", &seat);

    if (seat < 1 || seat > sizes[row - 1]) {
        printf("Invalid seat! This seat does not exist in this row.\n");
        return;
    }

    if (*(rows[row - 1] + seat - 1) == 1) {
        printf("Booking failed! This seat is already booked.\n");
        return;
    }

    *(rows[row - 1] + seat - 1) = 1;

    printf("Seat booked successfully!\n");
}
