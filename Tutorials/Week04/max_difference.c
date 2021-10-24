// Week 4 Tutorial
// Program that takes in an array of integers and returns the difference
// between the smallest and largest numbers in it.
// 
// Dan Nguyen (z5206032)
// 2018/08/23
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

#define MAX_NUMBER 999999

double max_difference (int numbers[], int num_elements);

int main (void) {
    
    int size = 0;
    
    printf("Enter an array size: ");
    scanf("%d", &size);
    
    int numbers[MAX_NUMBER];
    
    // get array
    int i = 0;
    int noRead = 1;
    
    while (noRead == 1 && i < size) {
        printf("Enter integer: ");
        noRead = scanf("%d", &numbers[i]);
        i++;
    }
    
    // prints the maximum difference
    printf("Maximum Difference: %f\n", max_difference(numbers, size));
    
    return 0;
}

// function that finds the maximum difference of an array
double max_difference (int numbers[], int num_elements) {
    
    int min = numbers[0];
    int max = numbers[0];
    int i = 0;
    int sum = 0;
    
    // finds minimum number in numbers[]
    while (min >= numbers[i] && i < num_elements) {
        min = numbers[i];
        printf("\n------------\n");
        printf("minimum is %d\n", min);
        printf("numbers[%d] = %d\n", i, numbers[i]);
        printf("\n------------\n");
        i++;
    }
    
    i = 0;
    
    // finds maximum number in numbers[]
    while (max <= numbers[i] && i < num_elements) {
        max = numbers[i];
        printf("\n------------\n");
        printf("maximum is %d\n", max);
        printf("numbers[%d] = %d\n", i, numbers[i]);
        printf("\n------------\n");
        i++;
    }
    
    // finds maximum difference of numbers[]
    sum = max - min;
    
    return sum;
}