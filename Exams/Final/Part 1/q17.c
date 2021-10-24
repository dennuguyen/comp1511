#include <stdio.h>

int main(void) {

    char goals[] = "All your goals belong to us.";
    char *a, *b, *c;

    a = goals + 5;
    b = &goals[10];
    c = goals + (b - goals) + (b - a);
    
    return 0;
}