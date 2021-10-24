#include <stdio.h>

int main(void) {

    int x = -9;
    int *p1 = &x;
    int *p2;

    p2 = p1;
    printf("%d\n", *p2);
    *p2 = 10;
    printf("%d\n",x);

    return 0;
}