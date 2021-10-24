// Week 3 Lab
// Program that counts down from 10.
// 
// Dan Nguyen (z5206032)
// 2018/08/06
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int counter = 10;
    
    while(counter >= 0 && counter <= 10) {
        printf("%d\n", counter);
        counter--;
    }
    
    return 0;
}