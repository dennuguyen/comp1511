// Week 2 Lab
// Program that words inputted numbers.
// 
// Dan Nguyen (z5206032)
// 2018/08/02

#include <stdio.h>

int main(void) {
    
    int num = 0;
    
    printf("Please enter an integer: ");
    scanf("%d", &num);
    
    if( num > 0 && num < 6 ) {
        printf("You entered ");
        if(num == 1) {
            printf("one.");
        } else if(num == 2) {
            printf("two.");
        } else if(num == 3) {
            printf("three.");
        } else if(num == 4) {
            printf("four.");
        } else {
            printf("five.");
        }
    } else if(num > 5) {
        printf("You entered a number greater than five.");
    } else {
        printf("You entered a number less than one.");
    }
    
    printf("\n");
    
    return 0;
}