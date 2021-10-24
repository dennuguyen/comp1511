// Week 4 Tutorial
// Program that calculates dot product of two vectors of integers.
// 
// Dan Nguyen (z5206032)
// 2018/08/12
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int VECTOR_LENGTH = 0;
int dot_product (int vector1[VECTOR_LENGTH], int vector2[VECTOR_LENGTH]);

int main (void) {
    
    // Set the vector length.
    printf("\nEnter the size of the vectors: ");
    scanf("%d", &VECTOR_LENGTH);
        
    int input1, input2, count = 0;
    int vector1[VECTOR_LENGTH];
    int vector2[VECTOR_LENGTH];
    
    printf("\nEnter values for vector 1: ");
    
    // User inputs values for vector1.
    while (count < VECTOR_LENGTH) {
        scanf("%d", &input1);
        vector1[count] = input1;
        count++;
    }
    
    printf("\nEnter values for vector 2: ");
    
    count = 0;
    
    // User inputs values for vector2.
    while (count < VECTOR_LENGTH) {
        scanf("%d", &input2);
        vector2[count] = input2;
        count++;
    }
    
    // Prints the dot product.
    printf("\nDot Product: %d\n\n", dot_product(vector1, vector2));
    
    return 0;
}

// Function does the dot product of two vectors.
int dot_product (int vector1[VECTOR_LENGTH], int vector2[VECTOR_LENGTH]) {
    
    int count = 0;
    int sum = 0;
    int vectordot[VECTOR_LENGTH];
    
    // Multiplies corresponding entries of vector1 and vector2.
    while (count < VECTOR_LENGTH) {
        vectordot[count] = vector1[count] * vector2[count];
        count++;
    }
    
    count = 0;
    
    // Sums all entries of vectordot.
    while (count < VECTOR_LENGTH) {
        sum += vectordot[count];
        count++;
    }
    
    return sum;
}