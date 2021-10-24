// Week 2 Tutorial
// Program that gives the area of a rectangle.
//
// Dan Nguyen (z5206032)
// 2018/07/28

#include <stdio.h>

int main(void) {
    
    int l = 0;
    int w = 0;
    int A = 0;
    
    printf("Please enter rectangle length: ");
    scanf("%d", &l);
    printf("Please enter rectangle width: ");
    scanf("%d", &w);
    
    A = w * l;
    
    printf("Area = %d\n", A);
    
    return 0;
}