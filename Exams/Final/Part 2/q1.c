#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

// return 1 if list is in strictly increasing order
// return 0 otherwise
int ordered(struct node *head) {
    
    int isIncreasing = 1;
    
    struct node *current = head;
    
    // if list is empty or there is one data in list then list cannot increase.
    if (head == NULL || head->next == NULL) {
        isIncreasing = 0;
    }
    
    while (current->next != NULL) {
        
        if (current->data >= current->next->data) {
            isIncreasing = 0;
        }
        
        current = current->next;
    }
    
    return isIncreasing;
}