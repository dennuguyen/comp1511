// Week 6 Tutorial
// Program that prints how many characters are in a line.
// 
// Dan Nguyen (z5206032)
// 2018/08/30
// 
// Dean Wunder

// stdout: print out from standard out
// stdin: read from standard in
// stderr: 
// fopen: 

#define BUFFER_LENGTH 1000

int main (void) {
    
    FILE *fp = fopen("file.txt", "");
    // first argument is name of file
    // second argument is how to open file (read, write (overwrites), pent (adds to end of tile))
    
    fputs("This is the first line!", fp);
    fclose(fp);
    
    return 0;
}

int main (void) {
    
    FILE *fp == fopen("file.txt", "r");
    char buffer[BUFFER_LENGTH];
    char *result = fgets(buffer, BUFFER_LLENGTH, fp);
    
    if (result == NULL) {
        fputs("Failed to read from file", stderr);
        return 1;
    }
    
    printf("%s\n", buffer);
    
    
    return 0;
}