// Alex Linker 2017-08-13
// This program prints out facts about a circle given its radius,
// using functions.

// Week 3 Lab
// 
// Edited by Dan Nguyen (z5206032)
// 2018/08/07
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}

double area(double radius) {
    double A = M_PI*radius*radius;
    
    return A;
}

double circumference(double radius) {
    double B = 2*M_PI*radius;
    
    return B;
}

double diameter(double radius) {
    double C = 2*radius;
    
    return C;
}