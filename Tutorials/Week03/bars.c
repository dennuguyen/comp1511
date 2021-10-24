// Week 3 Tutorial
// Prints bars.

#include <stdio.h>

int main(void) {
    int number;
    int row, column;
    
    printf("Enter size: ");
    scanf("%d", &number);
    
    row = 1;
    
    while(row <= number) {
    
        column = 1;
        
        while(column <= number) {
            if(column % 2 == 0) {
                printf("*");
            } else {
                printf("-");
            }
            column++;
        }
        
        printf("\n");
        row++;
    }
    return 0;
}