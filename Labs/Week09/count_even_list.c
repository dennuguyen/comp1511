// Week 9 Lab
// Program that counts the number of positive integers in a list.
// 
// Dan Nguyen (z5206032)
// 2018/09/18
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_even(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = count_even(head);
    printf("%d\n", result);

    return 0;
}


// return the number of even values in a linked list
int count_even(struct node *head) {
    
    struct node *current = head;
    
    int count = 0;
    
    while (current != NULL) {
        if (current->data % 2 == 0) {
            count++;
        }
        
        current = current->next;
    }
    
    return count;

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