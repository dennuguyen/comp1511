// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


// Print sum of : 1/1 + 1/3 + 1/5 + 1/7 + ... + 1/15

#include <stdio.h>

int main(void) {

    double sum, x; 

    sum = 0;

    x = 1;
     
    while (x <= 15 ) {
    
        sum = sum + (1.0/x) ;
        
        x = x + 2; 
        
    }

    printf("Sum  is %lf\n", sum);
    return 0;
}


