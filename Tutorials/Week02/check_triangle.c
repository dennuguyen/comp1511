// Week 2 Tutorial
// Program that checks whether triangle is valid in two dimensions.
//
// Dan Nguyen (z5206032)
// 2018/07/28

#include <stdio.h>

int main(void) {
    
    int a = 0;
    int b = 0;
    int c = 0;
    
    printf("Please enter three angles of triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if(a == 0 || b == 0 || c == 0) {
        printf("Triangle is invalid.\n");
    } else if(a + b + c != 180) {
        printf("Triangle is invalid.\n");
    } else {
        printf("Triangle is valid.\n");
    }
    
    return 0;
}