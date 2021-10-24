// Week 3 Lab
// Program that reads an integer, n, then draws an n x n spiral.
// 
// Dan Nguyen (z5206032)
// 2018/08/10
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main (void) {
    
    int m, n, i, j;
    int size = 0;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    i = j = 1;
    m = 1;
    
    // COULD SPIRAL JUST BE TWO DIAGONALLY MISALIGNED BOXES???
    
    while (m <= size) {
        
        n = 1;
        
        while (n <= size) {
            
        /*    // prints boxes in top-right corner.
            if ( (m + n < size + 1) && (m % 2 != 0) ) {
                printf("*");
                j++;
            } else if ( (m + n >= size + 1) && (n % 2 != 0) ) {
                printf("*");
                i++;
            }
            // everything before this comment is correct.
            
            else if ( (m + n >= size + 1) && (m > n) && (m < i)
                 && (m % 2 != 0) ) {
                printf("#");
                
                j--;
            }
            
            else if ( (m + n <= size + 1) && (m >= n) && (m < j)
                 && (n % 2 != 0) ) {
                printf("d");
                
                i--;
            } else {
                printf(" ");
            }*/
            
            
            if ( (m % 2 != 0) && (n == j) ) {
                printf("*");
                j++;
            } else if ( (
            
            n++;
        }
        
        printf("\n");
        m++;
    }

    return 0;
}