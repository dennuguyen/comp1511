// Read 5 numbers and print them in reverse order
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2018
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
// The constants 4 & 5 below would be better replaced with a #define

#include <stdio.h>

int main(void) {
    int x[5], i, j;
    printf("Enter 5 numbers: ");
    i = 0;
    while (i < 5) {
        scanf("%d", &x[i]);
        i = i + 1;
    }
    
    printf("Numbers reversed are:\n");
    j = 4;
    while (j >= 0) {
        printf("%d\n", x[j]);
        j = j - 1;
    }
    return 0;
}
