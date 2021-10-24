// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


// COMP1511 lecture example
//
// Read numbers until end of input (or a non-number)  is reached
// then print the maximum of the numbers
//
// Ashesh Mahidadia -
// 07/Aug/2018
//

#include <stdio.h>

int main(void) {
    int x, noRead, currentMin;

    printf("Enter number: ");
    noRead = scanf("%d", &x); 
    if(noRead != 1){
        printf("No number entered!\n");
        return 0;
    }
    currentMin = x;
    
    printf("Enter number: ");
    noRead = scanf("%d", &x); 
    while (noRead == 1) {
    
        if(x < currentMin) {
            currentMin = x; 
        }
        
        printf("Enter number: ");
        noRead = scanf("%d", &x); 
    }

    printf("Min of the numbers is %d\n", currentMin);
    
    return 0;
}


