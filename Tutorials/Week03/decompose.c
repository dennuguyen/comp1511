// Week 3 Tutorial
// Reads integer input and prints out individual digits of input.

#include <stdio.h>

#define MAX_NUMBER 99999

int digits(int number) {
    
    if (number == 0) {
        return 0;
    } else if (number % 9 == 0) {
        return 9;
    } else if (number % 8 == 0) {
        return 8;
    } else if (number % 7 == 0) {
        return 7;
    } else if (number % 6 == 0) {
        return 6;
    } else if (number % 5 == 0) {
        return 5;
    } else if (number % 4 == 0) {
        return 4;
    } else if (number % 3 == 0) {
        return 3;
    } else if (number % 2 == 0) {
        return 2;
    } else if (number % 1 == 0) {
        return 1;
    }
    
    return 'a';
}

int main(void) {
    
    int input = 0;
    float ten_thousands, thousands, hundreds, tens, ones;
    
    printf("Please enter an integer: ");
    scanf("%d", &input);
    
    printf("You entered %d which is decomposed: ", input);
    
    if (input > MAX_NUMBER) {
        
        // prints ERROR
        printf("\n--------\n");
        printf("ERROR");
        printf("\n--------\n");
        
    } else if (1 <= input/10000 && input/10000 < 10) { 
        
        // prints ten thousands
        ten_thousands = input/10000;
        printf("%d ", digits(ten_thousands));
        
        // prints thousands
        thousands = (input - 10000 * digits(ten_thousands)) / 1000;
        printf("%d ", digits(thousands));
        
        // prints hundreds
        hundreds = (input - 10000 * digits(ten_thousands)
            - 1000 *digits(thousands)) / 100;
        printf("%d ", digits(hundreds));
        
        // prints tens
        tens = (input - 10000 * digits(ten_thousands) - 1000 *
            digits(thousands) - 100 * digits(hundreds)) / 10;
        printf("%d ", digits(tens));
        
        // prints ones
        ones = input - 10000 * digits(ten_thousands)- 1000 *
            digits(thousands) - 100 * digits(hundreds) - 10 * digits(tens);
        printf("%d", digits(ones));
        
    } else if (1 <= input/1000 && input/1000 < 10) {
        
        // prints thousands
        thousands = input/1000;
        printf("%d ", digits(thousands));
        
        // prints hundreds
        hundreds = (input - 1000 * digits(thousands)) / 100;
        printf("%d ", digits(hundreds));
        
        // prints tens
        tens = (input - 1000 * digits(thousands)
            - 100 * digits(hundreds)) / 10;
        printf("%d ", digits(tens));
        
        // prints ones
        ones = (input - 1000 * digits(thousands)
            - 100 * digits(hundreds) - 10 * digits(tens));
        printf("%d", digits(ones));
        
    } else if (1 <= input/100 && input/100 < 10) {
        
        // prints hundreds
        hundreds = input/100;
        printf("%d ", digits(hundreds));
        
        // prints tens
        tens = (input - 100 * digits(hundreds)) / 10;
        printf("%d ", digits(tens));
        
        // prints ones
        ones = (input - 100 * digits(hundreds) - 10 * digits(tens));
        printf("%d", digits(ones));
        
    } else if (1 <= input/10 && input/10 < 10) {
    
        // prints tens
        tens = input/10;
        printf("%d ", digits(tens));
        
        // prints ones
        ones = input - 10 * digits(tens);
        printf("%d", digits(ones));
        
    } else if (1 <= input/1 && input/1 < 10) {
        // prints ones
        digits(input);
        printf("%d", digits(input));
        
    } else {
        // prints ERROR
        printf("\n--------\n");
        printf("ERROR");
        printf("\n--------\n");
    }
    
    printf("\n");
    
    return 0;
}