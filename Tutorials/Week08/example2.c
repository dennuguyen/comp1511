struct pod *read_sighting(FILE *stream);

struct pod *read_sightings_file(char filename[]) {
    FILE *fp = fopen(filename, "r"); //open filename for reading
    
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        exit(1); // in stdlib and will stop program
    }
    
    struct node *curr;
    struct node *prev = NULL; // prev
    
    while ((curr = read_sighting(fp)) != NULL) {
    // sets curr as read_sighting AND check if equal to NULL
        prev -> next = curr;
        prev = curr;
    }
    
    fclose(fp);
    
}