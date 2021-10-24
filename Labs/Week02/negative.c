// Week 2 Lab
// Program that determines whether a number is positive, negative or zero.
//
// Dan Nguyen (z5206032)
// 2018/07/31

#include <stdio.h>

int main(void) {
    
    int num;
    
    scanf("%d", &num);
    
    if(num > 0) {
        printf("You have entered a positive number.\n");
    } else if(num < 0) {
        printf("Don't be so negative!\n");
    } else {
        printf("You have entered zero.\n");
    }
    
    return 0 ;
}