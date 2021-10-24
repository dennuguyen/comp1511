// Week 5 Lab
// Program that decrypts a caesar shift.
// 
// Dan Nguyen (z5206032)
// 2018/08/25
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main (int argc, char *argv[]) {
    
    int c = getchar();
    int shift = atoi(argv[1]);
    
    
    return 0;
}

int decrypt (int c, int shift) {


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