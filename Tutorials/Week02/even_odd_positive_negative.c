// Week 2 Tutorial
// Program that determines whether an integer is even or odd.
//
// Dan Nguyen (z5206032)
// 2018/07/28

#include <stdio.h>

int main(void) {
    
    int a = 0;
    
    printf("Please enter a number: ");
    scanf("%d", &a);
    
    if(a > 0) {
        if(a%2 == 0) {
            printf("Positive Even Integer\n");
        } else {
            printf("Positive Odd Integer\n");
        }
    } else if(a < 0) {
        if(a%2 == 0) {
            printf("Negative Even Integer\n");
        } else {
            printf("Negative Odd Integer\n");
        }
    } else {
        printf("ZERO\n");
    }
    
    return 0;
}