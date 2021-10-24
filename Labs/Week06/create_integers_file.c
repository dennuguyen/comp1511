// Week 6 Lab
// Program which takes 3 arguments:
// First and second arguments define a range of integers
// Third will specify a filename
// 
// Dan Nguyen (z5206032)
// 
// 2018/09/01
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>

int argumentType (char input);
int argumentNumber (char frequency);

int main (int argc, char *argv[]) {
    
    char input1 = *argv[1];
    char input2 = *argv[2];
    
    argumentType(input1);
    argumentType(input2);
    argumentNumber(argc);
    
    FILE *stream = fopen(argv[3], "w");
    
    // if file fails to be created
    if (stream == NULL) {
        fprintf(stderr, "ERROR: '%s' failed to open\n", argv[3]);
        return 1;
    }
    
    // introduce range
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    
    // if max < min
    if (max < min) {
        int hold = max;
        max = min;
        min = hold;
    }
    
    int i = min;
    
    // fprints integers in range to file
    while (i <= max) {
        fprintf(stream, "%d\n", i);
        i++;
    }
    
    fclose(stream);
    
    return 0;
}


// Function that fprints when user inputs incorrect argument type
int argumentType (char input) {

    if (('a' <= input && input <= 'z') ||
        ('A' <= input && input <= 'Z')) {
        
        fprintf(stderr, "ERROR: Specified range is not an integer\n");
        return 1;
    }
    
    return 0;
}

// Function that fprints when user inputs incorrect number of arguments
int argumentNumber (char frequency) {

    if (frequency != 4) {
        fprintf(stderr, "ERROR: Number of arguments not 3\n");
        return 1;
    }
    
    return 0;
}