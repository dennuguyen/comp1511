// Week 4 Lab
// Test file to test the function "arrayAverage".
// 
// Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <math.h>

double arrayAverage(int a[], int size);

void checkArrayAverage(int test_no, int a[], int size,
    double expected_answer);

int main(int argc, char *argv[]) {
 
    int a1[]  = {1, 2, 3};
    checkArrayAverage(1, a1, 3, 2.0); 
    
    int a2[]  = {5, 2, 6, 1};
    checkArrayAverage(2, a2, 4, 3.5);     

    int a3[]  = {7, 10, 3, 21};
    checkArrayAverage(3, a3, 4, 10.25);
    
    int a4[]  = {-10, -40, -1, -25};
    checkArrayAverage(4, a4, 4, -19);
    
    return 0;
}

void checkArrayAverage(int test_no, int a[], int size,
    double expected_answer) {

    double student_answer = arrayAverage(a, size);
    
    // Prints passed test.
    printf("------------- \n");
    if (fabs(student_answer - expected_answer) < 0.000001) {
        printf("Test %d Passed\n\n", test_no);
        return;
    }
    
    // Prints failed test.
    printf("Test %d Failed!, see below for the expected answer.\n",
        test_no);
    int i = 0;
    printf("  Array is: ");
    while (i < size) {
        printf("%d, ", a[i]);
        i++; 
    }
    printf("\n");
    printf("  Average value, expected: %lf, your answer: %lf\n\n",
        expected_answer, student_answer);
}