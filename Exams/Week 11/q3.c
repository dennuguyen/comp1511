Session: 18s2
Assignment: week11_q3  Submission ID: 5206032


Your submission has been marked. + /usr/bin/less -m /import/ravel/4/z5206032/cs1511.week11_q3.mrk

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

S 0	Thu Oct 11 13:02:23 2018	z5206032 all q3 0

Sat Nov 10 00:43:42 2018		## flute09.orchestra.cse.unsw.EDU.AU ##
!!section listing
-rw------- cs1511exam/cs1511exam 817 2018-10-11 13:02 sensorCheck.c
C files ........
sensorCheck.c
dos2unix: converting file sensorCheck.c to Unix format ...

===============================================================================
-rw-r--r-- 1 cs1511 cs1511 817 Nov 10 00:43 sensorCheck.c
===============================================================================

     1	#include <stdio.h>
     2	#include <stdlib.h>
     3	#include <string.h>
     4	
     5	#include  "list.h" 
     6	
     7	/*  You need to implement this function.
     8	    Please see "struct node" in the file list.h.
     9	
    10	    The function should count and return number of times 
    11	    sensor2 is greater than sensor1 AND 
    12	    sensor2 is greater than sensor3. 
    13	*/
    14	
    15	int sensorCheck(struct node *head) {
    16	
    17	    // Implement this function 
    18	    // You also need to change the return value.
    19	    
    20	    int count = 0;
    21	    
    22	    struct node *current = head;
    23	    
    24	    if (head == NULL) {
    25	        return count;
    26	    }
    27	    
    28	    while (current != NULL) {
    29	        
    30	        if (current->sensor2 > current->sensor1 &&
    31	            current->sensor2 > current->sensor3) {
    32	            
    33	            count++;
    34	        }
    35	        
    36	        current = current->next;
    37	    }
    38	    
    39	    return count;
    40	}
    41	
    42	
    43	

!!section tests
** Test 1: 
--------------------------------
** Test passed
--------------------------------
** Test 2: 
--------------------------------
** Test passed
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
** Test passed
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
** Test passed
--------------------------------
** Test 9: 
--------------------------------
** Test passed
--------------------------------
** Test 10: 
--------------------------------
** Test passed
--------------------------------
** Test 11: 
--------------------------------
** Test passed
--------------------------------
!!section assess

!!perftab	** PERFORMANCE ANALYSIS **

Test  1 (0.25)	 ..  !!PASSed
Test  2 (0.25)	 ..  !!PASSed
Test  3 (0.5)	 ..  !!PASSed
Test  4 (0.5)	 ..  !!PASSed
Test  5 (0.5)	 ..  !!PASSed
Test  6 (0.5)	 ..  !!PASSed
Test  7 (0.5)	 ..  !!PASSed
Test  8 (0.5)	 ..  !!PASSed
Test  9 (0.5)	 ..  !!PASSed
Test 10 (0.5)	 ..  !!PASSed
Test 11 (0.5)	 ..  !!PASSed

!!perfmark	** TOTAL PERFORMANCE MARK:    5/5

!!marktab	**  MARKER'S  ASSESSMENT  **

!!finalmark	**  FINAL  ASSIGNMENT  MARK:	5/5

5206032	Nguyen, Dan Huy                        	3768/1 MTRNAH       

Autocommitted by jashankj:cs1511 at Sun Nov 11 16:15:14 AEDT 2018
