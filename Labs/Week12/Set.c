// Week 12 Lab
// 
// Dan Nguyen (z5206032)
// 2018/10/18
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Set.h"

struct _set {
    struct _set *next;
    int          data;
};

int main (void) {
    
    
    return 0;
}

// Create a new 'Set'.
Set newSet(void) {
    
    Set new = malloc(sizeof(Set));
    
    if (new == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        exit(0);
    }
    
    new->data = 0;
    new = NULL;
    
    return new;
}

// Release all resources associated with a 'Set'.
void destroySet(Set s) {
    
    struct _set *current = s;
    struct _set *temporary;
    
    while (current != NULL) {
        temporary = current->next;
        free(current);
        current = temporary;
    }
    
    free(s);
}

// Add an 'item' to the 'Set'.
void setAdd(Set s, item item) {
    
    struct _set *current = s;
    
    while (current->next != NULL) {
        
        if (current->data == item) {
            return;
        }
        
        current = current->next;
    }
    
    current->next->data = item;
    current->next->next = NULL;
}

// Remove an 'item' from the 'Set'.
void setRemove(Set s, item item) {
    
    struct _set *current = s;
    struct _set *temporary;
    struct _set *previous = current;
    
    while (current != NULL) {
        
        if (current->data == item) {
            temporary = current->next;
            free(current);
            previous->next = temporary;
        }
        
        previous = current;
        current = current->next;
    }
}

// Does the 'Set' contain this 'item'?
bool setContains(Set s, item item) {
    
    struct _set *current = s;
    
    while (current != NULL) {
        
        if (current->data == item) {
            return true;
        }
        
        current = current->next;
    }
    
    return false;
}

// How many items are in the 'Set'?
int setSize(Set s) {
    
    int count = 0;
    
    struct _set *current = s;
    
    while (current != NULL) {
        
        count++;
        
        current = current->next;
    }
    
    return count;
}

// Take the union of two sets.
Set setUnion(Set a, Set b) {
    
    struct _set *current_a = a;
    struct _set *current_b = b;
    
    while (current_a != NULL) {
        
        while (current_b != NULL) {
            
            if (setContains(a, b->data) == true) {
                setRemove(a, b->data);
            }
            
            current_b = current_b->next;
        }
        
        current_a = current_a->next;
    }
    
    return a;
}

// Take the intersection of two sets.
Set setIntersection(Set a, Set b) {
    
    
    struct _set *union_a_b = setUnion(a, b);
    struct _set *current_a = a;
    struct _set *current_b = b;
    
    // Get !intersection(a, b)
    while (current_a != NULL) {
        
        while (current_b != NULL) {
            
            if (setContains(a, b->data) == true) {
                setRemove(a, b->data);
            }
            
            current_b = current_b->next;
        }
        
        current_a = current_a->next;
    }
    
    // Union - !intersection(a, b) = intersection(a, b)
    
    
    return a;
}

// Is 'a' a subset of 'b'?
bool setSubset(Set a, Set b) {
    
}

// Is 'a' equal to 'b'.
bool setEqual(Set a, Set b) {
    
    // Sets are not equal if their sizes are not equal
    if (setSize(a) == setSize(b)) {
        return false;
    }
    
    struct _set *current_a = a;
    struct _set *current_b = b;
    
    // Check if elements of set are same
    while (current_a != NULL) {
        
        while (current_b != NULL) {
            
            if (current_a->data == current_b->data) {
                break;
            }
            
            current_b = current_b->next;
        }
        
        if (current_a->data != current_b->data) {
            return false;
        }
        
        current_a = current_a->next;
    }
    
    return true;
}