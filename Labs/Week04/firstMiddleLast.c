// Week 4 Lab
// Find and print the first, middle, and last elements of an array.
// 
// Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void printFirstMiddleLast(int size, int array[MAX_LENGTH]);

int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    // Declare the array.
    int array[MAX_LENGTH] = {};

    printf("Enter array values: ");
    // Intialise the array values.
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i = i + 1;
    }

    printFirstMiddleLast(size, array);

    return 0;
}

// Prints the first, middle, and last values of an array, on separate lines.
void printFirstMiddleLast(int size, int array[MAX_LENGTH]) {
    
    printf("%d\n", array[0]);
    printf("%d\n", array[size / 2]);
    printf("%d\n", array[size - 1]);
}