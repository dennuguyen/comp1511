#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int start, finish;
    
    printf("Enter start: ");
    scanf("%d", &start);
    
    printf("Enter finish: ");
    scanf("%d", &finish);
    
    int number = start;
    
    while (number <= finish) {
        
        if (number % 13 == 0) {
            printf("%d\n", number);
        }
        
        number++;
    }
    
    return 0;
}