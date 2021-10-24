// Week 4 Lab
// Prints out an array in the format "[1, 2, 3, ...]".
// 
// Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <assert.h>

void show_array(int size, int array[size]);

int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // Declare the array.
    int array[size];

    printf("Enter array values: ");
    // Initialise the array values.
    int i = 0;
    while (i < size) {
        assert(scanf("%d", &array[i]) == 1);
        i = i + 1;
    }

    show_array(size, array);

    return 0;
}

// Prints the array in the format [1, 2, 3, ...].
void show_array(int size, int array[size]) {
    
    int count = 0;
    
    printf("[");
    while (count < size - 1) {
        printf("%d, ", array[count]);
        count++;
    }
    printf("%d]\n", array[count]);
}