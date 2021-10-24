// Week 5 Lab
// Program that encrypts a character input into a Caesar cipher.
// 
// Dan Nguyen (z5206032)
// 2018/08/21
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

int encrypt (int c, int shift);

int main (int argc, char *argv[]) {
    
    int c = getchar();
    int shift = atoi(argv[1]);
    
    while (c != EOF) {
        putchar(encrypt(c, shift));
        c = getchar();
    }
    
    return 0;
}

// function encrypts int c by using a caesar shift.
int encrypt (int c, int shift) {
    
    // for ascii range of upper case alphabet
    if ('A' <= c && c <= 'Z') {
        c = c - 'A' + shift;
        // A = 0, B = 1, C = 2, ...
        
        // negative c values need to be rectified
        if (c >= 0) {
            c = c % 26;
        } else {
            c = abs(c) % 26;
            // rectifies c into the range of the alphabet only
            
            c = 26 - c;
            // c shifts in direction from Z to A
            
            c = c % 26;
            // rectifies c into the range of the alphabet only
        }
        c = 'A' + c;
        
    // for ascii range of lower case alphabet
    } else if ('a' <= c && c <= 'z') {
        c = c - 'a' + shift;
        if (c >= 0) {
            c = c % 26;
        } else {
            c = abs(c) % 26;
            c = 26 - c;
            c = c % 26;
        }
        c = 'a' + c;
    }
    
    return c;
}