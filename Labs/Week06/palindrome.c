// Week 6 Labs
// Program that tests if string is a palindrome.
// 
// Dan Nguyen (z5206032)
// Junjie Zhu (z5216997)
// 2018/08/29
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <string.h>

#define MAXIMUM 4096
#define TRUE 1
#define FALSE 0

int palindrome (char *line);

int main (void) {
    
    char line[MAXIMUM];
    
    // Get string
    printf("Enter a string: ");
    fgets(line, MAXIMUM, stdin);
    
    // Prints whether palindrome or not
    if (palindrome(line) == TRUE) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    
    return 0;
}

// Function that determines whether string is a palindrome or not
int palindrome (char *line) {
    
    int i = 0;
    int j = strlen(line) - 2;
    
    while (i < j) {
        if (line[i] != line[j]) {
            return FALSE;
        }
        i++;
        j--;
    }
    
    return TRUE;
}