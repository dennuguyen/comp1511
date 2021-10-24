#include <stdio.h>

#define MAX_PLATE 10000

struct parking_fine {
    double amount;
    char number_plate[MAX_PLATE];
};

int read_parking_fine(struct parking_fine);

int main(void) {
    
    struct parking_fine *f = NULL;
    
    if (read_parking_fine(*f)) {
        printf("%lf %s\n", f->amount, f->number_plate);
    }
    
    return 0;
}

// return 1 if a parking fine is successfully was read, 0 otherwise
int read_parking_fine(struct parking_fine fine) {
    
    if (scanf("%lf", &(fine.amount)) != 1) {
    
        return 0;
    }
    
    return fgets(fine.number_plate, MAX_PLATE, stdin) != NULL;
}