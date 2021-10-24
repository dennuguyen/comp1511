// Week 13 Lab
// Prints only even integers from standard input until EOF
// 
// Dan Nguyen (z5206032)
// 2018/10/28
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

#define MAX_NUMBER 10000

int main(void) {
    
    int array[MAX_NUMBER];
    
    int i = 0;
    
    while (scanf("%d", &array[i]) == 1) {
        
        i++;
    }
    
    int j = 0;
    
    while (j < i) {
        
        if (array[j] % 2 == 0) {
            printf("%d ", array[j]);
        }
        
        j++;
    }
    
    printf("\n");
    
    return 0;
}