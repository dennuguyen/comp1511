// A simple program which reads integers in the range 1..99
// and prints snap and exits when the same number is read twice
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 10/4/13

#include <stdio.h>

#define LARGEST_NUMBER 99

int main(void) {
    int i, n, snap;
    int numberCounts[LARGEST_NUMBER + 1];
    i = 0;
    while (i < LARGEST_NUMBER) {
       numberCounts[i] = 0;
       i = i + 1;
    }
    snap = 0;
    while (snap == 0) {
        printf("Enter a number: ");
        scanf("%d", &n);
        if (n < 0 || n > LARGEST_NUMBER) {
            printf("number has to be between 0 and 99 inclusive\n");
        } else {
            numberCounts[n] = numberCounts[n] + 1;
            if (numberCounts[n] > 1) {
                printf("Snap!\n");
                snap = 42;
            }
        }
    }

    return 0;
}
