// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


#include <stdio.h>

int sum(int a[], int size) {
    int sum = 0;
    
    int i = 0;     
    while(i < size){
        sum = sum + a[i] ;
        i = i + 1;  
    }
    return sum;
}

int main(void) {

    int a[5] = {4, 10, 2, 6, 3};
     
    int sumValue = sum(a, 5);
      
    printf("Sum is %d \n ", sumValue);

    return 0;
}
