// Week 3 Lab
// Program that reads a positive integer, n, and prints all positive integers
// less than n and divisible by 3 or 5.
// 
// Dan Nguyen (z5206032)
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int n = 0;
    int m = 1;
    
    printf("Enter number: ");
    scanf("%d", &n);
    
    while(m < n) {
        if(m % 3 == 0 || m % 5 == 0 ) {
            printf("%d\n", m);
        }
        m++;
    }
    
    return 0;
}