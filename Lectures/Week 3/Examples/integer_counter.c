// A simple program which reads integers in the range 1..99
// and prints how many time each integer has been read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 10/4/18

#include <stdio.h>

#define LARGEST_INTEGER 99

int main(void) {
    // the array element at index i
    // contains a count of how many times integer i has been seen
    int integer_counts[LARGEST_INTEGER + 1];

    // initialise all array elements to zero
    // this could also be done by changing the declaration to
    // int integer_counts[LARGEST_INTEGER + 1] = {0};

    int i = 0;
    while (i < LARGEST_INTEGER) {
       integer_counts[i] = 0;
       i = i + 1;
    }

    while (1) {
        int n;
        printf("Enter a number: ");
        if (scanf("%d", &n) != 1) {
            return 0;
        }

        if (n < 0 || n > LARGEST_INTEGER) {
            printf("number has to be between 0 and %d inclusive\n", LARGEST_INTEGER);
        } else {
            integer_counts[n] = integer_counts[n] + 1;
            printf("You have entered %d %d times\n", n, integer_counts[n]);
        }
    }

}
