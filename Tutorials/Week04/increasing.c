// Week 4 Tutorial
// Program returns 0 when series decreases and 1 if not.
// 
// Dan Nguyen (z5206032)
// 2018/08/15
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

#define ARRAY_LENGTH 5

int increasing (int array[]);

int main (void) {
    
    int array[ARRAY_LENGTH] = {0};
    
    printf("Enter integers into a 5 dimension array: ");
    
    int count = 0;
    
    while (count < ARRAY_LENGTH) {
        scanf("%d", &array[count]);
        count++;
    }
    
    if (increasing(array) == 1) {
        // no square brackets after array because we want to send entire array.
        printf("INCREASING.\n");
    } else {
        printf("NOT INCREASING.\n");
    }
    
    return 0;
}

int increasing (int array[]) {
    
    int i = 0;
    
    while (i < ARRAY_LENGTH - 1) { // "- 1" stops the loop one cycle earlier
        if (array[i] > array[i + 1]) {
            return 0;
        }
        i++;
    }
    return 1;
}