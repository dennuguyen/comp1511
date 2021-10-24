// Week 3 Lab
// Program that orders a set of integers from smallest to largest.
// 
// Dan Nguyen (z5206032)
// 2018/08/04
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int a, b, c;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    
    printf("The integers in order are: ");
    
    if(a <= b && a <= c) {
        if(b <= c) {
            printf("%d %d %d", a, b, c);
        } else if(c <= b) {
            printf("%d %d %d", a, c, b);
        }
    } else if(b <= a && b <= c) {
        if(a <= c) {
            printf("%d %d %d", b, a, c);
        } else if(c <= a) {
            printf("%d %d %d", b, c, a);
        }
    } else if(c <= a && c <= b) {
        if(a <= b) {
            printf("%d %d %d", c, a, b);
        } else if(b <= a) {
            printf("%d %d %d", c, b, a);
        }
    }
    
    printf("\n");
    
    return 0;
}