// A simple program which reads integers and prints snap
// and exits if the same number is read twice in a row
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 25/3/2018
//

#include <stdio.h>

int main(void) {
    int currentN, previousN;

    printf("Enter a number: ");
    scanf("%d", &previousN);

    printf("Enter a number: ");
    scanf("%d", &currentN);

    while (currentN != previousN) {
        previousN = currentN;
        printf("Enter a number: ");
        scanf("%d", &currentN);
    }

    printf("Snap!\n");
    return 0;
}
