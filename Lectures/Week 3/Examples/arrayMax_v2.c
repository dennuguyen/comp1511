// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


#include <stdio.h>

int findMax( int a[], int size){
    
    int curMax = a[0]; 
    int j = 1; 
    while(j < size){
    
        if( a[j] > curMax){
            curMax = a[j];
        }
        j++ ;   // j = j + 1    
    }
    return curMax;
}

int main(void) {
    int a[5], i;
    printf("Enter 5 numbers: ");
    i = 0;
    while (i < 5) {
        scanf("%d", &a[i]);
        i = i + 1;
    }
    
    int maxValue = findMax(a, 5);
      
    printf("Max is %d \n ", maxValue);

    return 0;
}
