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

int printWondrous(int num);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    // Get the number.
    int number;
    printf ("Enter a number: ");
    scanf("%d", &number);

    // Call printWondrous and save the count.
    int count = printWondrous(number);

    printf("The count is %d.\n", count);

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

// Wondrous Sequence Rules
// 1. If the current term is even: the next term is half the current term.
// 2. If the current term is odd: the next term is three times the current
//    term, plus one.
// 
// Need to printf \n after last '1'.
// Return the number of terms.
// Print out the sequence.
int printWondrous(int num) {
    
    int count = 1;
    
    printf("%d ", num);
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        printf("%d ", num);
        count++;
    }
    printf("\n");
    
    return count;
}