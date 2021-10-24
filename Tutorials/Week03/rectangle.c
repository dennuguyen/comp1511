// Week 3 Tutorial
// Prints rectangle.

#include <stdio.h>

int main(void) {
    
    int i, j;
    int height = 0;
    int length = 0;
    
    printf("Enter rectangle height and length: ");
    scanf("%d %d", &height, &length);
    
    i = 1;
    
    while(i <= height) {
    
        j = 1;
        
        while(j <= length) {
            if(j == 1 || j == length || i == 1 || i == height) {
                printf("*");
            } else {
                printf(" ");    
            }    
            j++;
        }
        
        printf("\n");
        i++;
    }
    
    return 0;
}