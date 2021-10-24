// Week 2 Tutorial
// Program that converts degree Fahrenheit to degree Celsius.
//
// Dan Nguyen (z5206032)
// 2018/07/28

#include <stdio.h>

int fah_to_cel(float fah0) {
     
     float cel = (fah0 - 32) * 5/9;
     
     return cel;
}

int main(void) {
    
    float fah = 0;
    
    printf("Please enter the temperature in degree Fahrenheit: ");
    scanf("%f", &fah);
    
    float cel = fah_to_cel(fah);
    
    printf("The temperature in degree Celsius is %f\n", cel);
    
    return 0;
}