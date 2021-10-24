// Week 3 Lab
// Program that determines whether a year is a leap year.
// 
// Dan Nguyen (z5206032)
// 2018/08/04
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
    
    return 0;
}