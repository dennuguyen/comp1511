// Week 12 lab
// Recursive Function - Factorial
// 
// Dan Nguyen (z5206032)
// 2018/10/18
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

int gcdRec (int a, int b);

int main (void) {
    
    // gcd = greatest common denominator of integers a AND b
    int a, b, gcd;
    
    printf("Enter value for a: ");
    scanf("%d", &a);
    
    printf("Enter value for b: ");
    scanf("%d", &b);
    
    gcd = gcdRec(a, b);
    
    printf("Greatest common denominator of a and b: %d\n", gcd);
    
    return 0;
}

// Euclid's Algorithm:
// If r is the remainder when b divises a, then the common divisors of a and b
// are precisely the same as the common divisors of b and r.
//                          gcd(a, b) = gcd(b, r)

int gcdRec (int a, int b) {
    
    // c is the complement of r in gcd
    int c = b;
    
    if (a == 0) {
        
        // gcd of 0 and b is b
        c = b;
        
    } else if (b == 0) {
        
        // gcd of a and 0 is a
        c = a;
        
    } else {
        
        // r is remainder of a/b
        int r = a % b;
        
        if (r == 0) {
            
            // base case
            // do nothing
        
        } else {
            
            // calls gcdRec
            c = gcdRec(c, r);
        }
    }
    
    return c;
}

/* personally prefer
int gcdRec (int a, int b) {
    
    // gcd of 0 and b is b
    if (a == 0) {
        return b;
    }
    
    // gcd of a and 0 is a
    if (b == 0) {
        return a;
    }
    
    // r is remainder of a/b
    int r = a % b;
    
    // c is the complement of r in gcd
    int c = b;
    
    // base case
    if (r == 0) {
        return c;
    }
    
    // return calls gcdRec
    return c = gcdRec(c, r);
}
*/