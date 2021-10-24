#include <stdio.h>

struct node {
    int data;
    struct node *next;
}

struct node *set_intersection(struct node *set1, struct node *set2) {
    
    if (set1 == NULL || set2 == NULL) {
        return NULL;
    }
    
    struct node *current1 = set1;
    struct node *current2 = set2;
    struct node *intersection = malloc(sizeof(struct node));
    struct node *previous = NULL;
    
    
    while (current1 != NULL) {
        
        while (current2 != NULL) {
            
            if (current1->data == current2->data) {
                intersection->data = current1->data;
                intersection->next = previous;
                previous = intersection;
            }
            
            current2 = current2->next;
        }
        
        current1 = current1->next;
    }
    
    return intersection;
}