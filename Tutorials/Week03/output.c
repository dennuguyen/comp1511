#include <stdio.h>

#define FIRST_NUMBER     10
#define SECOND_NUMBER    20
#define TOTAL   FIRST_NUMBER + SECOND_NUMBER
#define AVERAGE TOTAL / 2

int main(void) {
    printf("The average of %d and %d is %d\n",
        FIRST_NUMBER, SECOND_NUMBER, AVERAGE);
    
    return 0;
}

// output is "The average of 10 and 20 is 20"
// forgot to use brackets
//      #define TOTAL (FIRST_NUMBER + SECOND_NUMBER)
//      #define AVERAGE (TOTAL / 2)