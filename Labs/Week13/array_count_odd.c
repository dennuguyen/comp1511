// Week 13 Lab
// Program that counts number of odd integers in an array
// 
// Dan Nguyen (z5206032)
// 2018/10/27
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

# define TEST_ARRAY_SIZE 8

int count_odd(int length, int array[]);

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {16, 7, 8, 12, 13, 19, 21, 12};

    int result = count_odd(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}


// return the number of odd values in an array.
int count_odd(int length, int array[]) {
    
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 != 0) {
            count++;
        }
    }
    
    return count;
}