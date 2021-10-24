#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    
    assert(argv[1] != NULL);
    assert(argv[2] != NULL);
    
    int number = atoi(argv[1]);
    
    while (number <= atoi(argv[2])) {
        
        if (number % 13 == 0) {
            printf("%d\n", number);
        }
        
        number++;
    }
    
    return 0;
}