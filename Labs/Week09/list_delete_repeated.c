// Week 9 Lab
// Program that deletes consecutive repeated values in a list.
// 
// Dan Nguyen (z5206032)
// 2018/09/20
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int data;
};

struct node *delete_repeated(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_repeated(head);
    print_list(new_head);

    return 0;
}

// Delete any consecutive nodes with repeated values from the linked list.
// The deleted node is freed.
// If there are no consecutive nodes with repeated values, the list is
// not changed.
// The head of the list is returned.
struct node *delete_repeated(struct node *head) {
    
    struct node *current = head;
    struct node *temporary;
    
    // if list is empty
    if (head == NULL) {
        return NULL;
    }
    
    // deletes any repeated lists
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            temporary = current->next->next;
            free(current->next);
            current->next = temporary;
        } else {
            current = current->next;
        }
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