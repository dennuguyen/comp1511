#include <stdio.h>

int main(void) {

    int x = -9;
    int y = 0;

    while (x != 0){
        y = y - 1;
        x = x + 1;
    }

    printf("%d\n", x);
    printf("%d\n",y);
    
    return 0;
}