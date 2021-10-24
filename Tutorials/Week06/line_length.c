// Week 6 Tutorial
// Program that prints how many characters are in a line.
// 
// Dan Nguyen (z5206032)
// 2018/08/30
// 
// Dean Wunder

#include <stdio.h>

int string_length(char *string);

int main (void) {
    
    char *string = "characters";
    
    printf("Length: %d\n", string_length(string));
    
    return 0;
}

int string_length(char *string) {
    
    int length = 0;
    
    while (string[length] != '\0') {
        length++;
    }
    
    return length;
}