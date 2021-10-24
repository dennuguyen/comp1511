// Week 2 Lab
// Program that determines your dating range.
//
// Dan Nguyen (z5206032)
// 2018/08/02

#include <stdio.h>

int main(void) {
    
    int upper_lim = 0;
    int lower_lim = 0;
    int age = 0;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    lower_lim = age/2 + 7;
    upper_lim = 2 * (age - lower_lim) + age;
    
    if(upper_lim <= lower_lim ) {
        printf("You are too young to be dating.");
    } else {
        printf("Your dating range is %d to %d years old.", lower_lim, upper_lim);
    }
    
    printf("\n");
    
    return 0;
}