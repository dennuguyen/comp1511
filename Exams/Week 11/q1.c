Session: 18s2
Assignment: week11_q1  Submission ID: 5206032


Your submission has been marked. + /usr/bin/less -m /import/ravel/4/z5206032/cs1511.week11_q1.mrk

!!section banner
#######  #####    ###    #####    ###    #####   #####
#       #     #  #   #  #     #  #   #  #     # #     #
#             # # #   # #       # #   #       #       #
 #####   #####  #  #  # ######  #  #  #  #####   #####
      # #       #   # # #     # #   # #       # #
#     # #        #   #  #     #  #   #  #     # #
 #####  #######   ###    #####    ###    #####  #######

5206032	Nguyen, Dan Huy                        	3768/1 MTRNAH       

Submissions:-

S 0	Thu Oct 11 13:12:37 2018	z5206032 all q1 0

Sun Nov 11 00:01:08 2018		## flute09.orchestra.cse.unsw.EDU.AU ##
!!section listing
-rw------- cs1511exam/cs1511exam 1513 2018-10-11 13:12 promote_node.c
C files ........
promote_node.c
dos2unix: converting file promote_node.c to Unix format ...

===============================================================================
-rw-r--r-- 1 cs1511 cs1511 1513 Nov 11 00:01 promote_node.c
===============================================================================

     1	#include <stdio.h>
     2	#include <stdlib.h>
     3	
     4	#include  "list.h" 
     5	
     6	/*  You need to implement this function.
     7	
     8	    If you prefer, you can write your own helper functions in this file.      
     9	    You MUST NOT use any helper function from "list.h" in this file.
    10	        
    11	    For example, you MUST NOT use any of the following functions from "list.h"  
    12	    in your solution:
    13	        struct node *create_list(int data[], int size);
    14	        int  compare_lists(struct node *head1, struct node *head2);
    15	        void print_list(struct node *head);
    16	*/
    17	
    18	
    19	
    20	struct node *promote_node(struct node *head, int index){
    21	
    22	    // Implement this function 
    23	    // You also need to change the return value.
    24	    
    25	    struct node *current = head;
    26	    struct node *index_node = head;
    27	    
    28	    if (head == NULL) {
    29	        return NULL;
    30	    }
    31	    
    32	    // if head is index_node or index is negative. List is unchanged
    33	    if (head->data == index || index < 0) {
    34	        return head;
    35	    }
    36	    
    37	    while (current->next != NULL) {
    38	        
    39	        // current stops before the index_node
    40	        if (current->next->data == index) {
    41	            
    42	            // let index_node = where current is pointing
    43	            index_node = current->next;
    44	            
    45	            // let index_node POINT to head
    46	            index_node->next = head;
    47	            
    48	            // let current point to node after index_node
    49	            current->next = current->next->next;
    50	        }
    51	        
    52	        current = current->next;
    53	    }
    54	    
    55	    
    56	    return index_node;
    57	}
    58	
    59	
    60	

!!section tests
** Test 1: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input list:								Input list:
34 -> 12 -> 67 -> 24 -> 50 -> X						34 -> 12 -> 67 -> 24 -> 50 -> X

Test 1 failed: the head of the list was incorrect		     |	Test 1 passed!
								     <
See below for the expected answer.				     <
								     <
  Student  list: 34 -> 12 -> 67 -> 24 -> 50 -> X		     <
  Expected list: 24 -> 34 -> 12 -> 67 -> 50 -> X		     <
								     <
--------------------------------
** Test 2: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input list:								Input list:
-10 -> -5 -> -6 -> -55 -> -30 -> -2 -> X				-10 -> -5 -> -6 -> -55 -> -30 -> -2 -> X

Test 2 failed: the head of the list was incorrect		     |	Test 2 passed!
								     <
See below for the expected answer.				     <
								     <
  Student  list: -10 -> -5 -> -6 -> -55 -> -30 -> -2 -> X	     <
  Expected list: -6 -> -10 -> -5 -> -55 -> -30 -> -2 -> X	     <
								     <
--------------------------------
** Test 3: 
--------------------------------
** Test passed
--------------------------------
** Test 4: 
--------------------------------
** Test passed
--------------------------------
** Test 5: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input list:								Input list:
10 -> 20 -> X								10 -> 20 -> X

Test 5 failed: the head of the list was incorrect		     |	Test 5 passed!
								     <
See below for the expected answer.				     <
								     <
  Student  list: 10 -> 20 -> X					     <
  Expected list: 20 -> 10 -> X					     <
								     <
--------------------------------
** Test 6: 
--------------------------------
** Test passed
--------------------------------
** Test 7: 
--------------------------------
** Test passed
--------------------------------
** Test 8: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input list:								Input list:
3 -> 14 -> 5 -> X							3 -> 14 -> 5 -> X

Test 8 failed: the head of the list was incorrect		     |	Test 8 passed!
								     <
See below for the expected answer.				     <
								     <
  Student  list: 3 -> 14 -> 5 -> X				     <
  Expected list: 14 -> 3 -> 5 -> X				     <
								     <
--------------------------------
** Test 9: 
--------------------------------
** Test passed
--------------------------------
** Test 10: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input list:								Input list:
1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> X			1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> X

Test 10 failed: the head of the list was incorrect		     |	Test 10 passed!
								     <
See below for the expected answer.				     <
								     <
  Student  list: 1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> X <
  Expected list: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1 -> X <
								     <
--------------------------------
** Test 11: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
								     >	Input list:
								     >	1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> X
								     >
								     >	Test 11 passed!

Execution stopped by a CPU time limit.
Execution stopped here in promote_node(head=0xf5500710, index=5) in promote_node.c at line 52:

        }
        
-->     current = current->next;
    }
    


--------------------------------
!!section assess

!!perftab	** PERFORMANCE ANALYSIS **

Test  1 (0.25)	 ..  !!FAILed (-0.25)
Test  2 (0.25)	 ..  !!FAILed (-0.25)
Test  3 (0.5)	 ..  !!PASSed
Test  4 (0.5)	 ..  !!PASSed
Test  5 (0.5)	 ..  !!FAILed (-0.5)
Test  6 (0.5)	 ..  !!PASSed
Test  7 (0.5)	 ..  !!PASSed
Test  8 (0.5)	 ..  !!FAILed (-0.5)
Test  9 (0.5)	 ..  !!PASSed
Test 10 (0.5)	 ..  !!FAILed (-0.5)
Test 11 (0.5)	 ..  !!FAILed (-0.5)

!!perfmark	** TOTAL PERFORMANCE MARK:    2.5/5

!!marktab	**  MARKER'S  ASSESSMENT  **

!!finalmark	**  FINAL  ASSIGNMENT  MARK:	2.5/5

5206032	Nguyen, Dan Huy                        	3768/1 MTRNAH       

Autocommitted by jashankj:cs1511 at Sun Nov 11 15:25:24 AEDT 2018
