// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


#include <stdio.h>

int main(void) {
    int a[5], i, j;
    printf("Enter 5 numbers: ");
    i = 0;
    while (i < 5) {
        scanf("%d", &a[i]);
        i = i + 1;
    }
    
    
    int curMax = a[0]; 
    j = 1; 
    while(j < 5){
    
        if( a[j] > curMax){
            curMax = a[j];
        }
        
        j++ ;   // j = j + 1    
    }
    
    printf("Max is %d \n ", curMax);

    return 0;
}
