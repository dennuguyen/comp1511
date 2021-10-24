#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

struct node *copy(struct node *head) {
    
    if (head == NULL) {
        return NULL;
    }
    
    struct node *copy = malloc(sizeof(struct node));
    
    copy->data = head->data;
    copy->next = NULL;
    
    struct node *current = head->next;
    
    while (current != NULL) {
        
        struct node *new = malloc(sizeof(struct node));
        
        new->data = current->data;
        new->next = NULL;
        copy->next = new;
        
        current = current->next;
    }
    
    return copy;
}