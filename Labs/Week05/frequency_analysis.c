// Week 5 Lab
// Program that reads characters from input till end of input and prints
// the recurring frequency for each letter of the alphabet.
// 
// Dan Nguyen (z5206032)
// 2018/08/25
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main (void) {
    
    // alphabetCount stores recurrence of each letter
    int alphabetCount[26] = {0};
    
    // i represents element position in alphabetCount array
    int i = 0;
    
    // letterSum is required to calculate frequency as a fraction
    double letterSum = 0;
    int c = getchar();
    
    // get input from user to get total number of letters and get number
    // of each letter
    while (c != EOF) {
        
        // consider range for lower-case and upper-case letters separately
        if ('a' <= c && c <= 'z') {
            
            // convert ascii to element position in alphabetCount
            // a = 0, b = 1, ... , z = 26
            i = (c - 'a') % 26;
            
            // increase count for element (letter) in i'th position
            alphabetCount[i]++;
            letterSum++;
        } else if ('A' <= c && c <= 'Z') {
            i = (c - 'A') % 26;
            alphabetCount[i]++;
            letterSum++;
        }
        
        c = getchar();
    }
    
    i = 0;
    
    // prints recurrence of letters
    while (i < 26) {
        
        // letter of alphabet
        int letter = i + 'a';
        
        // calculates frequency
        // note: int / int = int
        double frequency = alphabetCount[i] / letterSum;
        
        // prints the answer
        printf("'%c' %f %d\n", letter, frequency, alphabetCount[i]);
        i++;
    }
    
    return 0;
}