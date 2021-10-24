// Week 2 Lab
// Program that sums two inputted integers.
// 
// Dan Nguyen (z5206032)
// 2018/08/02

#include <stdio.h>

int sum(int a, int b) {
    
    int c = a + b;
    
    return c;
}

int main(void) {
    
    int a = 0;
    int b = 0;
    
    printf("Please enter two integers: ");
    scanf("%d %d", &a, &b);
    
    int c = sum(a, b);
    
    printf("%d + %d = %d\n", a, b, c);
    
    return 0;
}