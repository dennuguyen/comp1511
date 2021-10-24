#include <stdio.h>

int main(void) {

    int i = -7;
    int j = 0;

    while (i != 0){
        j = j - i;
        i = i + 1;
    }

    printf("%d\n", i);
    printf("%d\n", j);

    return 0;
}