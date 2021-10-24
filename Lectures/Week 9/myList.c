#include <stdio.h>
#include <stdlib.h>

#include  "myList.h" 


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


int findMax(struct node *head){

    if(head == NULL){
        fprintf(stderr, "Error, list is empy \n");
        return 0;
    }


    if( head->next == NULL ){
        return head->data;
    }
    else {
    
        int subSolution = findMax(head->next); 
        
        if(head->data > subSolution){
            return head->data;
        }
        else {
            return subSolution; 
        }
    }

}


struct node *findR(struct node *head, int val){

    if(head == NULL ){
        return NULL; 
    }
    
    else if(head->data == val){
        return head; 
    }
    // data at current node is NOT equal to val
    // so find val in the "rest" of the list
    else {
    
        struct node *subProblemAnswer = findR(head->next, val);
        return subProblemAnswer;
    }
}

int noOdd(struct node *head){

    if(head == NULL) {
        return 0;
    }

    else {
        int count = 0;
        if( (head->data % 2) == 1) {
            count = 1;
        }
        
        int subSolution = noOdd(head->next); 
        return subSolution + count;     
    }
}



int noFail(struct node* head, int passMark){

    if(head == NULL) {
        return 0;
    }

    else {
         int count = 0;
         if(head->data < passMark){
            count = 1; 
        }
        
        int restNoFail = noFail(head->next, passMark); 
        
        return restNoFail + count;     
    }
}


