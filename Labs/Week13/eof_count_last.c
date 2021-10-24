// Week 13 Lab
// Program that counts how many times the last integer in the list has occured
// in the whole list
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
    int count = 0;
    
    while (j < i) {
        
        if (array[j] == array[i - 1]) {
            count++;
        }
        
        j++;
    }
    
    printf("%d\n", count);
    
    return 0;
}