// Week 3 Lab
// Program that uses a function to determine whether a year is a leap year.
// 
// Dan Nguyen (z5206032)
// 2018/08/04
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int isLeapYear(int leapyear) {
    
    if( (leapyear % 4 == 0 && leapyear % 100 != 0) || leapyear % 400 == 0 ) {
        return 1;
    }
    
    return 0;
}

int main(void) {
    
    int year = 0;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    if(isLeapYear(year) == 0) {
        printf("%d is not a leap year.\n", year);
    } else {
        printf("%d is a leap year.\n", year);
    }
    
    return 0;
}