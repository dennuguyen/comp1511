// Week 3 Tutorial
// Prints triangle.

#include <stdio.h>

int main(void) {
    int number;
    int row, column_dash, column_asterisk;
    
    printf("Enter size: ");
    scanf("%d", &number);
    
    row = 1;
    
    while(row <= number) {
    
        column_dash = number;
        
        while(column_dash > row) {
            printf("-");
            column_dash--;
        }
        
        column_asterisk = 1;
        
        while(column_asterisk <= row) {
            printf("*");
            column_asterisk++;
        }
        
        printf("\n");
        row++;
    }
    return 0;
}