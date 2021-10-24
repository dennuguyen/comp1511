// A simple program which reads integers and prints snap
// and exits if the same number is read twice
//
// Note the use of return to leave the main function
// and hence finish program execution
//
// Andrew Taylor - andrewt@unsw.edu.au (30/4/18)
// Modified by Ashesh Mahidadia (08/08/2018)
// 

#include <stdio.h>

#define MAX_NUMBERS 100000

int findNum(int a[], int start, int end, int value) {
    int i = start;
    while( i < end ){
        if( a[i] == value ) {  // found 
            return 1;  // return TRUE
        }
        i++; 
    }
    return 0;   // return FALSE
}

int main(void) {
    int numbers[MAX_NUMBERS];
    int countNumReadSoFar, i , value;

    countNumReadSoFar = 0;
    while (countNumReadSoFar < MAX_NUMBERS) {
    
        printf("Enter a number: ");        
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        
        int found_flag = findNum(numbers, 0, countNumReadSoFar, value) ;
        if(found_flag == 1){  // found value
                printf("Snap!\n");
                return 0;            
        }
        
        numbers[ countNumReadSoFar ] = value;
        countNumReadSoFar = countNumReadSoFar + 1;
       
    }
    
    printf("Sorry my array is full I have to stop!\n");
    return 0;
}
