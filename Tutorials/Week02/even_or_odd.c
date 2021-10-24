// Week 2 Tutorial
// Program determines whether integer is even or odd or negative.
//
// Dan Nguyen (z5206032)
// 2018/07/28

#include <stdio.h>

int main(void) {
    
    int a = 0;
    
    printf("Please enter a number: ");
    scanf("%d", &a);
    
    if(a > 0) {
        if(a % 2 == 0) {
            printf("EVEN\n");
        } else {
            printf("ODD\n");
        }
    } else if(a < 0) {
            printf("NEGATIVE\n");
    } else {
        printf("ZERO\n");
    }
    
    return 0;
}