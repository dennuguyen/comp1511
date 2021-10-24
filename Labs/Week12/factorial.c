// Week 12 lab
// Recursive Function - Factorial
// 
// Dan Nguyen (z5206032)
// 2018/10/18
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

long long factorial (long long n);

int main (void) {
    
    long long iteration = 0;
    
    printf("Enter number of iterations: ");
    scanf("%lld", &iteration);
    
    long long value = factorial(iteration);
    
    printf("Factorial: %lld\n", value);
    
    return 0;
}

// Recursive function that calculates factorial
long long factorial (long long index) {
    
    long long value = index;
    
    if (index == 0) {
        // if 0! = 1
        value = 1;
        
    } else if (index == 1) {
        // base case
        // do nothing
        
    } else {
    
        // calls factorial
        value = index * factorial(index - 1);
    }
    
    return value;
}

/* Personally prefer
// Recursive function that calculates factorial
long long factorial (long long index) {
    
    long long value = index;
    
    // if 0! = 1
    if (index == 0) {
        return 1;
    }
    
    // base case
    if (index == 1) {
        return value;
    }
    
    // return calls factorial
    return value = index * factorial(index - 1);
}
*/