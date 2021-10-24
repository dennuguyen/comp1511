#include <stdio.h>

#define MAX_NUMBER 100

int main(void) {
    
    int array[MAX_NUMBER];
    
    int i = 0;
    
    while (scanf("%d", &array[i]) == 1) {
        
        i++;
    }
    
    printf("%d numbers read. Median was %d\n", i, array[i/2]);
    
    return 0;
}