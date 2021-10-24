// Week 4 Tutorial
// Program that stores the square of the index of the element.
// 
// Dan Nguyen (z5206032)
// 2018/08/12
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main (void) {
    
    int array[15];
    int input, output, square;
    
    input = 0;
    
    while (input < 15) {
        array[input] = input;
        input++;
    }
    
    printf("\n");
    output = 0;
    
    while (output < 15) {
        square = array[output] * array[output];
        printf("Element %d is %d\n", output, square);
        output++;
    }
    
    printf("\n");
    
    return 0;
}