// Week 6 Lab
// Program that prints first 10 lines of a file.
// If less than 10, then program will not print at all.
// 
// Dan Nguyen (z5206032)
// 2018/09/01
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM 1024

int argumentType1 (char input);
int argumentType2 (char input);
int argumentNumber (char frequency);

int main (int argc, char *argv[]) {
    
    int i = 0;
    char line[MAXIMUM];
    
    // for argc is 2 or 4 only, otherwise invalid arguments
    if (argc == 2) {
        
        FILE *stream = fopen(argv[1], "r");
        
        // if file fails to be created
        if (stream == NULL) {
            fprintf(stderr, "ERROR: '%s' failed to open\n", argv[1]);
            return 1;
        }
        
        // gets first 10 lines
        while (i < 10) {
            if (fgets(line, MAXIMUM, stream) != NULL) {
                printf("%s", line);
            } else {
                break;
            }
            
            i++;
        }
        
        fclose(stream);
        
    } else if (argc == 4) {
        //argumentType1(*argv[1]);
        //argumentType2(*argv[2]);
        
        FILE *stream = fopen(argv[3], "r");
        
        // if file fails to be created
        if (stream == NULL) {
            fprintf(stderr, "ERROR: '%s' failed to open\n", argv[3]);
            return 1;
        }
        
        while (i < atoi(argv[2])) {
            if (fgets(line, MAXIMUM, stream) != NULL) {
                printf("%s", line);
            } else {
                break;
            }
            
            i++;
        }
        
        fclose(stream);
        
    } else {
        argumentNumber(argc);
    }
    
    return 0;
}

// Function that fprints when user inputs anything other than "-n"
int argumentType1 (char input) {

    if (strcmp(&input, "-n") != 0) {
        
        fprintf(stderr, "ERROR: First argument is not '-n'\n");
        return 0;
    }
    
    return 0;
}

// Function that fprints when user inputs incorrect type for lineLimit
int argumentType2 (char input) {
    
    if ((('a' <= input && input <= 'z') ||
        ('A' <= input && input <= 'Z')) &&
        (atoi(&input) < 0)) {
        
        fprintf(stderr, "ERROR: Line limiter is not a positive integer\n");
        return 1;
    }
    
    return 0;
}

// Function that fprints when user inputs incorrect number of arguments
int argumentNumber (char frequency) {

    if (frequency != 4) {
        fprintf(stderr, "ERROR: Number of arguments not 1 or 3\n");
        return 1;
    }
    
    return 0;
}