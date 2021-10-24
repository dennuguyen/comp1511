// Week 3 Tutorial
// Prints diagonal.

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
            if(column == row) {
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