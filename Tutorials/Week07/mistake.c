// Need to pass by reference instead of pass by value because "f" and "fine"
// are not the same.
// Dereference the pointer and access member inside struct.
// * is used for:
// 1. Multiplication
// 2. Create a variable that is a pointer
// 3. Dereference a pointer (go to memory address and get value)

// C will interpret "*fine.amount" as
// Get fine.amount first then dereference
// but we want to dereference first to be able to get "fine.amount"
// Therefore use "fine->amount" (dereference AND go to)
// Make sure "fine" which is left of -> is NOT NULL
// Can use "assert(fine != NULL);"

// Golden Rules
// 1. Unintialised memory
// 2. Memory is within bounds
// 3. Never dereference a NULL pointer

#include <stdio.h>
#define MAX_PLATE 10000

struct parking_fine {
    double   amount;
    char     number_plate[MAX_PLATE];
};

int read_parking_fine(struct parking_fine *);

int main(void) {

    struct parking_fine f;

    if (read_parking_fine(&f)) {
        printf("%lf %s\n", f.amount, f.number_plate);
    }

    return 0;
}

// return 1 if a parking fine is successfully was read, 0 otherwise
int read_parking_fine(struct parking_fine *fine) {
    
    // assert(fine != NULL);
    // terminates program if condition is false
    if (fine == NULL) {
        return 0;
    }
    
    if (scanf("%lf", &(fine->amount)) != 1) {
        return 0;
    }
    
    return fgets(fine->number_plate, MAX_PLATE, stdin) != NULL;
}