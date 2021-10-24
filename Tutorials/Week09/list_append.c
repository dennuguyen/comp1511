#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
}

struct node *list_append (struct node *list1, struct node *list2);

struct node *list_append (struct node *list1, struct node *list2) {
    
    // if first list is NULL
    if (list1 == NULL) {
        return list2;
    }
    
    struct node *current = list1;
    
    // looks for next node to be NULL
    // thing on left of arrow must not be NULL (initially) - must check
    while (current->next != NULL) {
        
        
        current = current->next;
    }
    // by this stage, current must be the last element in the list
    
    current->next = list2;
    // joins list1 and list2 then return both lists together
    
    return list1;
}