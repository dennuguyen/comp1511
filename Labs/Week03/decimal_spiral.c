#include <stdio.h>

int digits (int number) {
    
    if (number == 0) {
        return 0;
    } else if (number % 9 == 0) {
        return 9;
    } else if (number % 8 == 0) {
        return 8;
    } else if (number % 7 == 0) {
        return 7;
    } else if (number % 6 == 0) {
        return 6;
    } else if (number % 5 == 0) {
        return 5;
    } else if (number % 4 == 0) {
        return 4;
    } else if (number % 3 == 0) {
        return 3;
    } else if (number % 2 == 0) {
        return 2;
    } else if (number % 1 == 0) {
        return 1;
    } else {
        return '?';
    }
}

int main (void) {
    
    int size = 0;
    int m, n, i, j;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    m = 1;
    
    while (m <= size) {
        
        n = 1;
        
        while (n <= size) {
            
            printf("%d", digits(n-m));
            
            n++;
        }
        
        printf("\n");
        m++;
    }
    
    return 0;
}