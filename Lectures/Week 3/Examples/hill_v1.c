// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 

// A simple program that detects "hill" of size 5
// It detects five or more consecative rising input values. 
//
// Ashesh Mahidadia - ashesh@cse.unsw.edu.au
// August 2018
//


#include <stdio.h>

int main(void) {
    int currentN, previousN;
    
    int count = 0; 

    printf("Enter a number: ");
    scanf("%d", &previousN);

    printf("Enter a number: ");
    scanf("%d", &currentN);

    while (currentN != previousN) {
    
        if(currentN > previousN) {
            count = count + 1;
        }
        else {
            count = 0; 
        }
        
        if(count >= 5){
            printf("Buyyyyyy!! \n");
        }
        
        //printf("currentN is %d, count is %d\n", currentN, count);
        
        previousN = currentN;
        
        printf("Enter a number: ");
        scanf("%d", &currentN);
    }


    return 0;
}
