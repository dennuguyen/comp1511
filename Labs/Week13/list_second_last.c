// Week 13 Lab
// Program that returns second last node's value
// 
// Dan Nguyen (z5206032)
// 2018/10/28
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int second_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = second_last(head);
    printf("%d\n", result);

    return 0;
}


// Return value of second-last element in linked list.
// The list assumed to have at least 2 elements.

int second_last(struct node *head) {
    
    struct node *current = head;
    
    while (current->next->next != NULL) {
        
        current = current->next;
    }
    
    return current->data;
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