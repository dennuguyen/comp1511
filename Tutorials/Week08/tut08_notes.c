// dcc
// dcc -valgrind
// dcc --leakcheck : checks for memory leaks

// malloc : changes a variable's lifetime (linked list will still persist when
// function dies)

// argument of malloc is usually sizeof() because unsure of how much memory of
// a struct is taken up

void write_sightings_file(char filename[], struct pod *first_pod) {
    
    FILE *fp = fopen(filename, "w");
    
    struct pod *curr = first_pod;
    // type is struct pod *
    // name is first_pod (only use name when calling first_pod)
    
    // struct pod *curr = *first_pod
    // dereferences first_pod
    
    // why use curr when not just use first_pod BECAUSE style (name is poor description)
    // pass by reference vs value
    // every variable in C is passed by value except for arrays and pointers
    // arrays ARE pointers
    
    while (curr != NULL) { // eventually curr reaches NULL
        
        write_sightings(fp, curr);
        
        curr = curr -> next; // reassign curr
        // left of -> should be a pointer and not NULL
        // if it is NULL may have segmentation fault
        
        // 
        
    }
    
    fclose(fp);
    
}