// Week 3 Tutorial
// Program that reads an integer and prints out that many asterisks.
// 
// Dan Nguyen (z5206032)
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int num = 0;
    int ast = 0;
    
    printf("Please enter an integer: ");
    scanf("%d", &num);
    
    while(ast < num) {
        printf("*\n");
        ast++;
    }
    
    return 0;
}