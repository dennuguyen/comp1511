// Week 9 Lab
// Program that deletes a value in a list
// 
// Dan Nguyen (z5206032)
// 2018/09/20
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

struct node {
    struct node *next;
    int data;
};

struct node *delete_contains(int value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s value list-elements\n", argv[0]);
        return 1;
    }
    int value = atoi(argv[1]);
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 2, &argv[2]);

    struct node *new_head = delete_contains(value, head);
    print_list(new_head);

    return 0;
}

// Delete the first node in the list containing the value `value`.
// The deleted node is freed.
// If no node contains `value`, the list is not changed.
// The head of the list is returned.
struct node *delete_contains(int value, struct node *head) {
    
    struct node *current = head;
    struct node *temporary;
    
    if (head == NULL) {
        return NULL;
    }
    
    if (current->data == value) {
        
        temporary = current->next;
        free(current);
        current = temporary;
        
        return current;
    }
    
    while (current->next != NULL) {
        if (current->next->data == value) {
            
            temporary = current->next->next;
            free(current->next);
            current->next = temporary;
            
            return head;
        }
        
        current = current->next;
    }
    
    return head;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
         printf("%d", n->data);
         if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}