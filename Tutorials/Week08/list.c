#include <stdhio.h>
#include <stdlib.h>

void print_list (struct node *first);

struct node {
    int value;
    struct node *next; // self-referential structure allows for linked lists
};

int main (void) {
    
    struct node *first = make_list;
    
    print_list(first);
    
    release_list(first); // release memory taken by malloc
}

void print_list (struct node *first) {
    struct node *current = first;
    
    while (current != NULL) {
        printf("%d\n", current -> value); //-> is used because current is a pointer
        
        current = current -> next;
    }
}

struct node *make_list ( ) { // struct node * because malloc returns a pointer
    struct node first = malloc(sizeof(struct node));
    struct node second = malloc(sizeof(struct node));
    struct node third = malloc(sizeof(struct node));
    
    first->value = 100;
    first->next = second; // points first to address of second
    second->value = 200;
    second->next = third;
    third->value = 300;
    third->next = NULL; // nothing comes after third
}

void release_list (struct node *first) {
        struct node *current = first;
    
    while (current != NULL) {
    //    free(current); // use after free error
    //    current = current -> next; // trying to access current after freed ?!?!
        
        struct node *tmp = current->next;
        free(current);
        current = tmp;
    }
}
}