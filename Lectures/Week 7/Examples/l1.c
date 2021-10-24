#include <stdio.h>
#include <stdlib.h>

/*
$ dcc /home/cs1511/public_html/18s1/code/lists/list_intro.c
$ ./a.out
a=0xf5500710 a->data=27 a->next=0xf55006f0
b=0xf55006f0 b->data=12 b->next=0xf55006d0
c=0xf55006d0 c->data=32 c->next=0xf55006b0
d=0xf55006b0 d->data=42 d->next=(nil)

p=0xf5500710 p->data=27 p->next=0xf55006f0
p=0xf55006f0 p->data=12 p->next=0xf55006d0
p=0xf55006d0 p->data=32 p->next=0xf55006b0
p=0xf55006b0 p->data=42 p->next=(nil)

113
*/

struct node {
    struct node *next;
    int         data;
};

void process_list(struct node *head);
int sum_list(struct node *head);

int main(int argc, char *argv[]) {

    struct node *a = malloc(sizeof (struct node));
    a->data = 27;
    a->next = NULL;
    printf("\nNode a:\n  a=%p a->data=%d a->next=%p\n", a, a->data, a->next);
        
    struct node *b = malloc(sizeof (struct node));
    b->data = 12;
    b->next = NULL;
    printf("\nNode b:\n  b=%p b->data=%d b->next=%p\n", b, b->data, b->next);
        
    struct node *c = malloc(sizeof (struct node));
    c->data = 32;
    c->next = NULL;
    printf("\nNode c:\n  c=%p c->data=%d c->next=%p\n", c, c->data, c->next);
        

    struct node *d = malloc(sizeof (struct node));
    d->data = 42;
    d->next = NULL;
    printf("\nNode d:\n  d=%p d->data=%d d->next=%p\n", d, d->data, d->next);

/**    
    a->data = 27;
    b->data = 12;
    c->data = 32;
    d->data = 42;
**/
    a->next = b;
    b->next = c;
    c->next = d;
    d->next= NULL;
    
    printf("---------------- ----------------\n\n");    
        
    printf("// After linking nodes: \n");
    printf("//    a->next is same as b\n");
    printf("//    b->next is same as c\n");   
    printf("//    and so on .. \n");                 
    printf("Node a:\n a=%p a->next=%p\n", a, a->next);
    printf("Node b:\n b=%p b->next=%p\n", b, b->next);
    printf("Node c:\n c=%p c->next=%p\n", c, c->next);
    printf("Node d:\n d=%p d->next=%p\n", d, d->next);

    printf("---------------- ----------------\n\n");    
    printf("// After linking nodes: \n");
    printf("//    a->next is same as b\n");
    printf("//    a->next->next is same as c\n");   
    printf("//    a->next->next->next is same as d\n");   
    printf("   Node a->data: %d \n", a->data);
    printf("   Node a->next->data: %d \n", a->next->data); 
    printf("   Node a->next->next->data: %d \n", a->next->next->data);     
    printf("   Node a->next->next->next->data: %d \n", a->next->next->next->data);         
    
    printf("---------------- ----------------\n\n");
    printf("//  Below: process_list(a) ....... \n\n");    
    process_list(a);
        
    printf("---------------- ----------------\n\n");
    printf("//  Below: sum_list(a) ....... \n\n");    
    int sum = sum_list(a);
    printf("Sum is %d\n", sum);
    
}


void prev_example(struct node *head) {
    struct node *prev = NULL;
    struct node *p = head;
    
    while (p != NULL) {
    
        printf("   p->data=%d \n", p->data );
        
        prev = p;
        p = p->next;
    }
}

void process_list(struct node *head) {
    struct node *p = head;
    
    while (p != NULL) {
    
        printf("   p->data=%d \n", p->data );
        
        p = p->next;
    }
}


int sum_list(struct node *head) {
    struct node *p = head;
    int total = 0;
    while (p != NULL) {
        printf("   p=%p p->data=%d p->next=%p\n", p, p->data, p->next);
        total = total + p->data;
        p = p->next;
    }
    return total;
}

