// implement functions

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct node {
    int value;
    struct node *next;
};

struct _queue {
    int n_items;
    struct node *head;
    struct node *tail;
};

Queue newQueue() {
    
    Queue new = malloc(sizeof(_queue));
    // sizeof(Queue) is wrong because Queue is only a pointer
    
    // Should check to see if malloc fails
    if (new == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        exit(1);
    }
    
    new->n_items = 0;
    new->head = NULL;
    
    return new;
}

void destroyQueue(Queue q) {
    
    assert (q != NULL);
    
    struct node *current = q->head;
    struct node *temporary;
    
    while (current != NULL) {
        temporary = current->next;
        free(current);
        current = temporary;
    }
    
    free(q);
}

int dequeue(Queue q) {
    
    assert(q != NULL);
    
    if (q->head == NULL) {
        return 0;
    }
    
    struct node *removed = q->head;
    q->head = q->head->next;
    
    int temp = removed->value;
    free(removed);
    
    return temp;
}

void enqueue(Queue q, int item) {
    
    assert (q != NULL);
    
    struct node *new_node = malloc(sizeof(node));
    
    if (new_node == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        exit(1);
    }
    
    struct node *current = q->head;
    
    if (current != NULL) {
        while (current->next != NULL) {
        
            current = current->next;
        }
        
        current->next = new_node;
        
    } else {
        q->head = new_node;
    }
}