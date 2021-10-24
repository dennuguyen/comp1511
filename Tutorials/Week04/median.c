// Week 4 Tutorial
// Program that prints the median of a set.
// 
// Dan Nguyen (z5206032)
// 2018/08/22
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

#define MAX_NUMBER 10000

int main (void) {
    
    int list[MAX_NUMBER];
    int noRead = 1;
    int i = 0;
    
    printf("Create your list!\n");
    
    // get list
    while (noRead != 0 && i < MAX_NUMBER) {
        printf("Enter entry: ");
        noRead = scanf("%d", &list[i]);
        i++;
    }
    
    i--;
    
    // get median
    printf("Median: %d\n", list[i/2]);
    
    return 0;
}