// Read 5 numbers and print them in reverse order
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2018

#include <stdio.h>

#define N_NUMBERS 5

int main(void) {
    int x[N_NUMBERS], i, j;

    printf("Enter %d numbers: ", N_NUMBERS);
    i = 0;
    while (i < N_NUMBERS) {
        scanf("%d", &x[i]);
        i = i + 1;
    }
    printf("Numbers reversed are:\n");
    j = N_NUMBERS - 1;
    while (j >= 0) {
        printf("%d\n", x[j]);
        j = j - 1;
    }
    return 0;
}
