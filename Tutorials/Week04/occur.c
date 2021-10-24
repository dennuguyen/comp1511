// Week 4 Tut
// Program which reads a list of  6 numbers and a reference number and prints
// out how many times the reference number has occurred in the list.
// 
// Dan Nguyen (z5206032)
// 2018/08/22
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main (void) {
    
    int list[6] = {0};
    int reference, counter = 0;
    int i = 0;
    
    printf("Enter 6 numbers: ");
    
    // initialise the list
    while (i < 6) {
        scanf("%d", &list[i]);
        i++;
    }
    
    // get reference number
    printf("Enter the reference number: ");
    scanf("%d", &reference);
    
    i = 0;
    
    // is reference number in list
    while (i < 6) {
        
        if (reference == list[i]) {
            counter++;
        }
        
        i++;
    }
    
    // prints the recurrence of the reference number in list.
    printf("%d occurred %d times.\n", reference, counter);
    
    return 0;
}