// Week 7 Lab
// Program that summarises every whale species, number of pods, and how many
// whales of that species was seen.
// 
// Dan Nguyen (z5206032)
// 2018/09/09
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <string.h>

#define MAX_SPECIES_NAME_LENGTH 128
#define MAX_SIGHTINGS 10000
#define MAX_WHALE_SPECIES 256
#define TRUE -1
#define FALSE -2

// a struct to represent the date
// a whale pod sighting was made
struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales
struct pod {
    struct date when;
    int how_many;
    char species[MAX_SPECIES_NAME_LENGTH];
};

int read_sightings_file(char filename[], int len, struct pod sightings[len]);
int read_sighting(FILE *f, struct pod *w);
int read_date(FILE *f, struct date *d);

void whale_summary(int n_sightings, struct pod sightings[n_sightings]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file> <species>\n", argv[0]);
        return 1;
    }

    struct pod whale_sightings[MAX_SIGHTINGS];
    int n_sightings = read_sightings_file(argv[1], MAX_SIGHTINGS,
        whale_sightings);

    if (n_sightings < 1) {
        return 1;
    }

    whale_summary(n_sightings, whale_sightings);

    return 0;
}

// a struct definition you can use if you wish
struct tally {
    int  pods;
    int  whales;
    char species[MAX_SPECIES_NAME_LENGTH];
};

//
// print a summary of all whale sightings
//

void whale_summary(int n_sightings, struct pod sightings[n_sightings]) {
    
    struct tally tally[MAX_WHALE_SPECIES] = {{0}};
    int new_species;
    int n_tally = 0;
    
    // run through all sightings
    for (int i = 0; i < n_sightings; i++) {
    
        new_species = TRUE;
        
        // tally can have at most 256 whale species
        // if species is not new by end of loop then exit loop
        for (int j = 0; j < MAX_WHALE_SPECIES &&
            new_species == TRUE; j++) {
            
            // compares whether species names are the same
            // if not then assumes is a new species (TRUE)
            if (strcmp(tally[j].species, sightings[i].species) == 0) {
                tally[j].pods++;
                tally[j].whales += sightings[i].how_many;
                new_species = FALSE;
            }
        }
        
        // creates an entry for new species
        if (new_species == TRUE) {
            strcpy(tally[n_tally].species, sightings[i].species);
            tally[n_tally].pods++;
            tally[n_tally].whales += sightings[i].how_many;
            n_tally++;
        }
    }
    
    // prints required message
    for (int k = 0; k < n_tally; k++) {
        printf("%d %s pods containing %d whales\n", tally[k].pods,
            tally[k].species, tally[k].whales);
    }
}

//
// DO NOT CHANGE THE FUNCTION BELOW HERE
//

// return number of sightings read from filename
// -1 is returned if there is an error
int read_sightings_file(char filename[], int len, struct pod sightings[len]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        return -1;
    }

    int n_sightings = 0;
    while (read_sighting(f, &sightings[n_sightings]) == 1 && n_sightings < len) {
        n_sightings = n_sightings + 1;
    }

    fclose(f);
    return n_sightings;
}

// return 1 if a sighting can be read, 0 otherwise
int read_sighting(FILE *f, struct pod *s) {
    if (read_date(f, &(s->when)) != 1) {
        return 0;
    }
    if (fscanf(f, "%d", &(s->how_many)) != 1) {
        return 0;
    }
    fgetc(f);
    if (fgets(s->species, MAX_SPECIES_NAME_LENGTH, f) == NULL) {
        return 0;
    }

    // finish string at '\n' if there is one
    char *newline_ptr = strchr(s->species, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // also finish string at '\r' if there is one - files from Windows  will
    newline_ptr = strchr(s->species, '\r');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }
    return 1;
}

// return 1 if a date can be read, 0 otherwise
int read_date(FILE *f, struct date *d) {
    int n_scanned = fscanf(f, "%d/%d/%d", &(d->year), &(d->month), &(d->day));
    return n_scanned == 3;
}