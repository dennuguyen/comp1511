#include <stdio.h>
#include <assert.h>

#define MAX_NUMBER 1000

int remove_char(char str[], char c);

int main(void) {
    
    char str[11] = "hello world";
    
    remove_char(str, 'l');
    
    printf("%s\n", str);
    
    return 0;
}

int remove_char(char str[], char c) {
    
    char *s = str;
    
    assert(s != NULL);
    
    int j = 0;
    
    while (s[j] != NULL) {
        j++;
    }
    
    for (int i = 0; i < MAX_NUMBER; i++) {
        
        if (c == s[i]) {
            
            return 1;
        }
    }
    
    return 0;
}