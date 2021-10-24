#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int non_decreasing (int n, int a[n]);

int main (void) {
    
    int array1[4] = {1, 2, 2, 3};
    
    printf("Result of non-decreasing for array1: %d \n", nondecreasing(4, array1);
    
    return 0;
}

int non_decreasing (int n, int a[n]) {
    
    int i = 0;
    
    int returnVal = TRUE;
    
    while (i < n - 1) { //stop loop one iteration earlier than n-1 because of uninitialised values
        
        if (a[i] > a[i+1]) {
            returnVal = FALSE;
        }
        
        i++;
    }
    
}