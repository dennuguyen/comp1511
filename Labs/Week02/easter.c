// Week 2 Lab
// Program that determines the date of Easter Sunday for any year.
// 
// Dan Nguyen (z5206032)
// 2018/08/02
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    
    int a, b, c, d, e, f, g, h, i, j, k, l, m, p;
    int easterYear, easterMonth, easterDate;
    
    printf("Enter year: ");
    scanf("%d", &easterYear);
    
    a = easterYear % 19;
    b = easterYear / 100;
    c = easterYear % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19 * a + b - d - g + 15) % 30;
    i = c / 4;
    k = c % 4;
    l = (32 + 2 * e + 2 * i - h - k) % 7;
    m = (a + 11 * h + 22 * l) / 451;
    easterMonth = (h + l - 7 * m + 114) / 31;
    p = (h + l - 7 * m + 114) % 31;
    easterDate = p + 1;
    
    printf("Easter is ");
    
    if(easterMonth == 1) {
        printf("January ");
    } else if(easterMonth == 2) {
        printf("February ");
    } else if(easterMonth == 3) {
        printf("March ");
    } else if(easterMonth == 4) {
        printf("April ");
    } else if(easterMonth == 5) {
        printf("May ");
    } else if(easterMonth == 6) {
        printf("June ");
    } else if(easterMonth == 7) {
        printf("July ");
    } else if(easterMonth == 8) {
        printf("August ");
    } else if(easterMonth == 9) {
        printf("September ");
    } else if(easterMonth == 10) {
        printf("October ");
    } else if(easterMonth == 11) {
        printf("November ");
    } else if(easterMonth == 12) {
        printf("December ");
    } else {
        printf("???");
    }
    
     printf("%d in %d.\n", easterDate, easterYear);
    
    return 0;
}