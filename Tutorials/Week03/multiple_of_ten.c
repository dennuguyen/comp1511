// Week 3 Tutorial
// Program that prints multiples of 10 in the range of two inputted values.
// 
// Dan Nguyen (z5206032)
// 2018/08/04
//
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int ini = 0;
    int fin = 0;
    
    printf("Enter start: ");
    scanf("%d", &ini);
    printf("Enter finish: ");
    scanf("%d", &fin);
    
    while(ini <= fin) {
        if(ini%10 == 0) {
            printf("%d\n", ini);
        }
        
        ini++;
    }
    
    return 0;
}