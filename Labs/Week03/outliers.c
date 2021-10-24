// Week 3 Lab
// Program that prints outliers to the range 5 to 25 inclusive.
// 
// Dan Nguyen (z5206032)
// 2018/08/07
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int num = 0;
    int count = -1;
    int exit = 1;
    
    while(exit == 1) {
        if(5 <= num && num <= 25) {
        } else {
            count++;
        }
        printf("Enter number: ");
        exit = scanf("%d", &num);
    }
    
    printf("\nOutliers: %d\n", count);
    
    return 0;
}