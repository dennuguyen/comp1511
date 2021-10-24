// Week 4 Lab
// Calculate the magnitude of a complex number
// 
// By Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _complex {
    double real;
    double imaginary;
} complex;

double complexAbsolute(complex c);

int main (int argc, char *argv[]) {

    complex c;

    printf("Enter the real part: ");
    scanf("%lf", &c.real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &c.imaginary);

    // Calculate the absolute value.
    double absoluteValue = complexAbsolute(c);

    printf("The absolute value is %.2lf.\n", absoluteValue);

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

// Calculate the magnitude (absolute value) of a complex number.
double complexAbsolute(complex c) {
    
    double abs = sqrt(c.real * c.real + c.imaginary * c.imaginary);

    return abs;
}