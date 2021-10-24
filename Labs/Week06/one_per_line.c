// Week 6 Labs
// Program that reads an input and prints the characters each per line.
// 
// Dan Nguyen (z5206032)
// 2018/08/29
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

#define MAX_NUMBER 2096

int main (void) {
    
    printf("Enter a string: ");
    
    char line[MAX_NUMBER];
    
    fgets(line, MAX_NUMBER, stdin);
    
    int i = 0;
    
    while (line[i] != '\n' && line[i] != '\0') {
        printf("%c\n", line[i]);
        i++;
    }
    
    return 0;
}