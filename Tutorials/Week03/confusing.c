// Test if a point is inside a triangle.
// Julian Saknussemm
// Edited by Dan Nguyen (z5206032)
// 2018/08/09
//
// Given Three points of a triangle, and another arbitrary point this program
// determines if that point lies inside the triangle.
//
// This is determined by satisfying the following rule:
// A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
// iff
// P is on the same side of the line AB as C
// P is on the same side of the line BC as A
// and
// P is on the same side of the line AC as B
//
// A special case exits for a vertical line (inf gradient) when testing
// the side of the line.

#include <stdio.h>

// checks if point is over the line.
int isPointOver (double px, double py, double m, double b);

// checks if two points lie on the same line.
int twoPoints (double px, double py, double m, double b,
    double lx, double ly);

// tritest checks if point is within the triangle.
int tritest (double x0, double y0, double x1, double y1,
    double x2, double y2, double px, double py);

int main (int argc, char* argv[]) {
    
    double x0, y0, x1, y1, x2, y2, px, py;

    int error_count = 0;

    // get input
    printf("Triangle Vertex A (x,y): ");
    error_count += scanf("%lf, %lf", &x0, &y0);
    
    printf("Triangle Vertex B (x,y): ");
    error_count += scanf("%lf, %lf", &x1, &y1);
    
    printf("Triangle Vertex C (x,y): ");
    error_count += scanf("%lf, %lf", &x2, &y2);
    
    printf("Test Point (x,y): ");
    error_count += scanf("%lf, %lf", &px, &py);

    // print error
    if (error_count < 8) {
        printf("You're stupid and didn't put in the right inputs!\n");     
        return 1;
    }

    // print answer
    printf("Point (%.2lf, %.2lf) is ", px, py);
    
    if (tritest(x0, y0, x1, y1, x2, y2, px, py)) {
        printf("inside");
    } else {
        printf("outside"); 
    }
    printf(" the Triangle\n");
    
    return 0;
}

int isPointOver (double px, double py, double m, double b) {
    
    if (py < m * px + b) {
        return -1; 
    } else if (py == m * px + b) {
        return 0;
    } else {
        return 1;
    }
}

int twoPoints (double px, double py, double m, double b,
    double lx, double ly) {
    
    return (isPointOver(px, py, m, b) == isPointOver(lx, ly, m, b));
}

int tritest (double x0, double y0, double x1, double y1,
    double x2, double y2, double px, double py) {
    
    // line eqns
    // b: y - y1 = m( x - x1 ), x = 0
    int line1, line2, line3;
    double m01 = (y1-y0)/(x1-x0);
    double b01 = m01 * -x1 + y1;
    double m02, m12, b02, b12;
    
    // vertical line checks
    m02 = (y2-y0)/(x2-x0);
    m12 = (y2-y1)/(x2-x1);
    b02 = m02 * -x2 + y2;
    b12 = m12 * -x2 + y2;
    
    // if x1 == x0, it is a vertical line
    if (x1 == x0) {
       line1 = ( (px <= x0) == (x2 <= x0) );
    } else {
       line1 = twoPoints(px, py, m01, b01, x2, y2);
    }

    if (x1 == x2) {
        line2 = ( (px <= x2) == (x0 <= x2) );
    } else {
        line2 = twoPoints(px, py, m12, b12, x0, y0);
    }

    if (x2 == x0) {
        line3 = ( (px <= x0 ) == (x1 <= x0) );
    } else {
        line3 = twoPoints(px, py, m02,b02, x1, y1);
    }

    return line1 && line2 && line3;
}

// added consistentspacing between variables
// changed variable names for better description
// moved comments to its own line
// space between if and argument
// indentations inside functions
// some variable arguments were too long so had to be truncated