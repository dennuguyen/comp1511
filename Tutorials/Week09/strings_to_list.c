#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
    struct node *next;
    int data;
}

struct node *strings_to_list (int length, char *strings[]);

int main (void) {
    return 0;
}

struct node *strings_to_list (int length, char *strings[]);
    
    int i = 0;
    
    
    struct node *previous = NULL;
    
    while (i < length) {
        // make the node
        
        struct node *new = malloc(sizeof(struct node));
        
        if (previous != NULL) {
            previous->next = new;
        }
        
        new->data = atoi(strings[i]);
        previous = new;=
        i++;
    }
    
    new->next = NULL;
    
}