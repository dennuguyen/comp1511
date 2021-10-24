#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

int identical(struct node *head1, struct node *head2) {
    
    struct node *current1 = head1;
    struct node *current2 = head2;
    
    int isIdentical = 1;
    
    while (current1 != NULL && current2 != NULL) {
        
        if (current1->data != current2->data) {
            isIdentical = 0;
            break;
        }
        
        current1 = current1->next;
        current2 = current2->next;
    }
    
    if ((current1 == NULL && current2 != NULL) || (current1 != NULL && current2 == NULL)) {
        isIdentical = 0;
    }
    
    return isIdentical;
}