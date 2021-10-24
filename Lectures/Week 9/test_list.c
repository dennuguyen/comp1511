#include <stdio.h>
#include <stdlib.h>

#include  "myList.h" 

int main(int argc, char *argv[]) {

    struct node *head = create_node(67, NULL);
  
    head = create_node(33, head);
    head = create_node(77, head);    
    head = create_node(25, head);
    head = create_node(10, head);
    
    //struct node *p = create_node(120, NULL);
    
    print_list(head); 
    printf("\n");  

    int fails = noFail(head, 50); 
    printf("noFail: %d \n", fails);
      
      
    struct node *p = findR(head, 60);
    if(p != NULL) {
        printf("p->data is: %d \n", p->data);
    }
    else {
        printf("Value not found! \n");    
    }
        
    return 0;
}





