// Week 2 Lab
// Program that determines if Matilda has enough money for icecream.
//
// Dan Nguyen (z5206032)
// 2018/07/31

#include <stdio.h>

int main(void) {
    
    int num = 0;
    int cost = 0;
    int total = 0;
    
    printf("How many scoops? ");
    scanf("%d", &num);
    
    printf("How many dollars does each scoop cost? ");
    scanf("%d", &cost);
    
    total = cost * num;
    
    if(total <= 10) {
        printf("You have enough money!\n");
    } else {
        printf("Oh no, you don't have enough money :(\n");
    }
    
    return 0;
}