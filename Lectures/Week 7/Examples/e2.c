
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int         data;
};

struct node *create_node(int data, struct node *next);
void print_list(struct node *head);
struct node *find_node(struct node *head, int data);

struct node *insert_ordered(struct node *head, struct node *node);
struct node *delete(struct node *head, struct node *node);

int
main(int argc, char *argv[]) {

    struct node *head = create_node(97, NULL);
    head = create_node(68, head);
    head = create_node(42, head);    
    head = create_node(25, head);
    head = create_node(10, head);

    print_list(head); 
    printf("\n");        
        
    return 0;
}

// Create a new struct node containing the specified data,
// and next fields, return a pointer to the new struct node.

struct node *create_node(int data, struct node *next) {
    struct node *n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}

// return pointer to first node with specified data value
// return NULL if no such node

struct node *find_node(struct node *head, int data) {
    struct node *n = head;

    // search until end of list reached
    while (n != NULL) {
        // if matching item found return it
        if (n->data == data) {
            return n;
        }

        // make node point to next item
        n = n->next;
    }

    // item not in list
    return NULL;
}

// print contents of list in Python syntax

void print_list(struct node *head) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");
}



