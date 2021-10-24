// Week 3 Lab
// Program that reads integer, n, then prints n x n pattern of asterisks and
// dashes in the shape 'X'.
// 
// Dan Nguyen (z5206032)
// 2018/08/07
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int m, n;
    int num = 0;
    
    printf("Enter size: ");
    scanf("%d", &num);
    
    // Logic
    // 
    // From drawing a m x n matrix and looking at the position of elements:
    // Left main diagonal will always have m = n.
    // Right main diagonal will always have n + m = num + 1 (pattern).
    
    m = 1;
    
    while(m <= num) {
        
        n = 1;
        
        while(n <= num) {
            if(n == m || n + m == num + 1) {
                printf("*");
            } else {
                printf("-");
            }
            n++;
        }
        
        printf("\n");
        m++;
    }
    
    return 0;
}