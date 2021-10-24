#include <stdio.h>

#define MAX_NUMBER 10000

int main(void) {
    
    int number, multiple, noRead, array[MAX_NUMBER][MAX_NUMBER];
    
    int i = 0;
    
    while (noRead != 0) {
        printf("Enter integer: ");
        scanf("%d", &number);
        printf("Enter multiplier: ");
        scanf("%d", &multiple);
        
        array[i][i] = {
            {number},
            {multiple}
        };
        
        i++;
    }
    
    return 0;
}