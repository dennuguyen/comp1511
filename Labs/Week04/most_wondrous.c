// Week 4 Lab
// Takes an integer and prints out a "Wondrous Sequence" starting with that
// number, followed by a single new line character.
// 
// Dan Nguyen (z5206032)
// 2018/08/17
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

int mostWondrous(int num);

int main (int argc, char *argv[]) {

    int number;
    scanf("%d ", &number);

    int length = mostWondrous(number);

    printf("has length %d.\n", length);

    return EXIT_SUCCESS;
}

// Wondrous Sequence Rules
// 1. If the current term is even: the next term is half the current term.
// 2. If the current term is odd: the next term is three times the current
//    term, plus one.
int mostWondrous(int num) {
    
    int length = 1;
    
    while (num < 1234) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        printf("%d ", num);
        length++;
    }
    printf("\n");
    
    return length;
}