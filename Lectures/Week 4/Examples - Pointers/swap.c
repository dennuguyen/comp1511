// Simple example of using pointer to pass reference to variables
// Andrew Taylor - andrewt@unsw.edu.au
// 29/4/18

#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char *argv[]) {
    int x = 42;
    int y = 13;

    printf("x=%d y=%d\n", x, y);

    swap(&x, &y);

    printf("x=%d y=%d\n", x, y);

    return 0;
}
