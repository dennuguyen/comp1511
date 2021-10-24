// Week 2 Tutorial
// Program that determines whether you passed or failed.
//
// Dan Nguyen (z5206032)
// 2018/07/28

#include <stdio.h>

int main(void) {

    int mark = 0;
    
    printf("Please enter your mark: ");
    scanf("%d", &mark);
    
    if(mark >= 0 && mark < 50) {
        printf("You failed... :L\n");       
        if(mark == 0) {
            printf("Consider transfering...\n");
        }
    } else if(mark >= 50 && mark <= 100) {   
        printf("You passed...\n");        
        if(mark == 100) {
            printf("... with flying colours! :D\n");
        }
    } else {
        printf("Error\n");
    }
    
    return 0;
}
    