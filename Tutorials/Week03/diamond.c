// Week 3 Tutorial
// Prints diamond.

#include <stdio.h>

int main(void) {
    
    int i, j, border, left, right;
    int side = 0;
    
    printf("Enter side length: ");
    scanf("%d", &side);
    
    border = 2 * side - 1;
    left = right = side;
    i = 1;
    
    while(i <= border) {
        
        j = 1;
        
        while(j <= border) {
            
            if(j == left || j == right) {
                printf("*");
            } else {
                printf(" ");
            }
            
            j++;
        }
        
        
        printf("\n");
        i++;
        
        if(i > side) {
            left++;
            right--;
        } else {
            left--;
            right++;
        }
    }
    
    return 0;
}