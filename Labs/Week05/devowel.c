// Week 5 Lab
// Program that omits all vowels and sends it back.
// 
// Dan Nguyen (z5206032)
// 2018/08/21
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int vowel_remover (int character);

int main (void) {
    
    int c = getchar();
    
    while (c != EOF) {
        
        if (vowel_remover(c) == 0) {
            putchar(c);
        }
        c = getchar();
    }
    return 0;
}

// function returns 1 if character is a lower case vowel.
int vowel_remover (int c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    return 0;
}