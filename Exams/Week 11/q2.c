Session: 18s2
Assignment: week11_q2  Submission ID: 5206032


Your submission has been marked. + /usr/bin/less -m /import/ravel/4/z5206032/cs1511.week11_q2.mrk

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

S 0	Thu Oct 11 13:12:26 2018	z5206032 all q2 0

Sat Nov 10 01:30:15 2018		## flute09.orchestra.cse.unsw.EDU.AU ##
!!section listing
-rw------- cs1511exam/cs1511exam 1104 2018-10-11 13:12 pointsFirstQuadrant.c
C files ........
pointsFirstQuadrant.c
dos2unix: converting file pointsFirstQuadrant.c to Unix format ...

===============================================================================
-rw-r--r-- 1 cs1511 cs1511 1104 Nov 10 01:30 pointsFirstQuadrant.c
===============================================================================

     1	#include <stdio.h>
     2	#include <stdlib.h>
     3	#include <string.h>
     4	
     5	#include  "q2.h" 
     6	
     7	/*  You need to implement this function.
     8	*/
     9	
    10	void  pointsFirstQuadrant(char label[], int size, struct point points[size],
    11	                          int *in_quadrant1_p, int *not_in_quadrant1_p ) {
    12	
    13	    // Implement this function 
    14	    // You also need to change the following values.
    15	    
    16	    // if the points are "InFirstQuadrant" then x-values and y-values
    17	    // should be both positive
    18	    
    19	    int i = 0;
    20	    int in = 0;
    21	    int out = 0;
    22	    
    23	    while (i < size) {
    24	        
    25	        if (strcmp(label, &points->label[i]) == 0) {
    26	           
    27	            // x and y must be positive to be in Quadrant1
    28	            if (points[i].x > 0 && points[i].y > 0) {
    29	                
    30	                // count the number of points in Quad1
    31	                in++;
    32	            } else {
    33	                
    34	                // count the number of points not in Quad1
    35	                out++;
    36	            }
    37	        }
    38	        
    39	        i++;
    40	    }
    41	    
    42	    // pointing to address of int
    43	    *in_quadrant1_p = in; 
    44	    *not_in_quadrant1_p = out;
    45	}
    46	
    47	
    48	

!!section tests
** Test 1: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 02, y: -6, label: redyellow)					 0:   (x: 02, y: -6, label: redyellow)
 1:   (x: 10, y: 20, label: red)					 1:   (x: 10, y: 20, label: red)
 2:   (x: -17, y: 64, label: blue)					 2:   (x: -17, y: 64, label: blue)
 3:   (x: -4, y: -5, label: red)					 3:   (x: -4, y: -5, label: red)
 4:   (x: 06, y: 06, label: red)					 4:   (x: 06, y: 06, label: red)
------------- 								------------- 
Test 1 Failed: incorrect answer					     |	Test 1 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 0 ,  Expected: 2 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 1 		     <
--------------------------------
** Test 2: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 03, y: 08, label: id224)					 0:   (x: 03, y: 08, label: id224)
 1:   (x: -5, y: -2, label: id250)					 1:   (x: -5, y: -2, label: id250)
 2:   (x: 05, y: 06, label: id224)					 2:   (x: 05, y: 06, label: id224)
 3:   (x: -10, y: -1, label: id224)					 3:   (x: -10, y: -1, label: id224)
------------- 								------------- 
Test 2 Failed: incorrect answer					     |	Test 2 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 1 ,  Expected: 2 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 1 		     <
--------------------------------
** Test 3: 
--------------------------------
** Test passed
--------------------------------
** Test 4: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 09, y: 01, label: hello)					 0:   (x: 09, y: 01, label: hello)
 1:   (x: -2, y: -2, label: world)					 1:   (x: -2, y: -2, label: world)
 2:   (x: -5, y: 06, label: this)					 2:   (x: -5, y: 06, label: this)
 3:   (x: 06, y: -2, label: is)						 3:   (x: 06, y: -2, label: is)
 4:   (x: 04, y: 04, label: hello)					 4:   (x: 04, y: 04, label: hello)
 5:   (x: -1, y: -5, label: hello)					 5:   (x: -1, y: -5, label: hello)
 6:   (x: -6, y: 03, label: world)					 6:   (x: -6, y: 03, label: world)
 7:   (x: 03, y: -5, label: this)					 7:   (x: 03, y: -5, label: this)
 8:   (x: 02, y: 01, label: is)						 8:   (x: 02, y: 01, label: is)
 9:   (x: -9, y: -8, label: goodbybe)					 9:   (x: -9, y: -8, label: goodbybe)
------------- 								------------- 
Test 4 Failed: incorrect answer					     |	Test 4 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 1 ,  Expected: 2 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 1 		     <
--------------------------------
** Test 5: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 03, y: 05, label: orange)					 0:   (x: 03, y: 05, label: orange)
 1:   (x: 01, y: 08, label: orangered)					 1:   (x: 01, y: 08, label: orangered)
 2:   (x: 04, y: 09, label: ORANGE)					 2:   (x: 04, y: 09, label: ORANGE)
 3:   (x: 01, y: 07, label: orange)					 3:   (x: 01, y: 07, label: orange)
 4:   (x: 05, y: 09, label: orange)					 4:   (x: 05, y: 09, label: orange)
 5:   (x: 09, y: 03, label: orangee)					 5:   (x: 09, y: 03, label: orangee)
 6:   (x: 02, y: 02, label: oranger)					 6:   (x: 02, y: 02, label: oranger)
 7:   (x: 06, y: 08, label: orangest)					 7:   (x: 06, y: 08, label: orangest)
 8:   (x: 05, y: 08, label: orange)					 8:   (x: 05, y: 08, label: orange)
 9:   (x: 03, y: 04, label: oran)					 9:   (x: 03, y: 04, label: oran)
------------- 								------------- 
Test 5 Failed: incorrect answer					     |	Test 5 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 1 ,  Expected: 4 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 0 		     <
--------------------------------
** Test 6: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: -3, y: -5, label: orange)					 0:   (x: -3, y: -5, label: orange)
 1:   (x: -1, y: -8, label: orangered)					 1:   (x: -1, y: -8, label: orangered)
 2:   (x: -4, y: -9, label: ORANGE)					 2:   (x: -4, y: -9, label: ORANGE)
 3:   (x: -1, y: -7, label: orange)					 3:   (x: -1, y: -7, label: orange)
 4:   (x: -5, y: -9, label: orange)					 4:   (x: -5, y: -9, label: orange)
 5:   (x: -9, y: -3, label: orangee)					 5:   (x: -9, y: -3, label: orangee)
 6:   (x: -2, y: -2, label: oranger)					 6:   (x: -2, y: -2, label: oranger)
 7:   (x: -6, y: -8, label: orangest)					 7:   (x: -6, y: -8, label: orangest)
 8:   (x: -5, y: -8, label: orange)					 8:   (x: -5, y: -8, label: orange)
 9:   (x: -3, y: -4, label: oran)					 9:   (x: -3, y: -4, label: oran)
------------- 								------------- 
Test 6 Failed: incorrect answer					     |	Test 6 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 0 ,  Expected: 0 			     <
 (not_in_quadrant1) Your answer: 1 ,  Expected: 4 		     <
--------------------------------
** Test 7: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: -11, y: -11, label: &)					 0:   (x: -11, y: -11, label: &)
 1:   (x: -11, y: 11, label: A)						 1:   (x: -11, y: 11, label: A)
 2:   (x: -11, y: 11, label: &)						 2:   (x: -11, y: 11, label: &)
 3:   (x: -11, y: 11, label: A)						 3:   (x: -11, y: 11, label: A)
 4:   (x: -11, y: 11, label: &)						 4:   (x: -11, y: 11, label: &)
 5:   (x: -11, y: 11, label: A)						 5:   (x: -11, y: 11, label: A)
 6:   (x: 11, y: 11, label: &)						 6:   (x: 11, y: 11, label: &)
 7:   (x: 11, y: 11, label: &)						 7:   (x: 11, y: 11, label: &)
------------- 								------------- 
Test 7 Failed: incorrect answer					     |	Test 7 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 0 ,  Expected: 2 			     <
 (not_in_quadrant1) Your answer: 1 ,  Expected: 3 		     <
--------------------------------
** Test 8: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: -11, y: -11, label: &)					 0:   (x: -11, y: -11, label: &)
 1:   (x: 11, y: 11, label: &)						 1:   (x: 11, y: 11, label: &)
 2:   (x: -11, y: -11, label: &)					 2:   (x: -11, y: -11, label: &)
 3:   (x: 11, y: 11, label: &)						 3:   (x: 11, y: 11, label: &)
 4:   (x: -11, y: -11, label: &)					 4:   (x: -11, y: -11, label: &)
 5:   (x: 11, y: 11, label: &)						 5:   (x: 11, y: 11, label: &)
 6:   (x: -11, y: -11, label: &)					 6:   (x: -11, y: -11, label: &)
 7:   (x: 11, y: 11, label: &)						 7:   (x: 11, y: 11, label: &)
------------- 								------------- 
Test 8 Failed: incorrect answer					     |	Test 8 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 0 ,  Expected: 4 			     <
 (not_in_quadrant1) Your answer: 1 ,  Expected: 4 		     <
--------------------------------
** Test 9: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 00, y: 01, label: z)						 0:   (x: 00, y: 01, label: z)
 1:   (x: 01, y: 01, label: b)						 1:   (x: 01, y: 01, label: b)
 2:   (x: 00, y: 01, label: a)						 2:   (x: 00, y: 01, label: a)
 3:   (x: -1, y: 01, label: a)						 3:   (x: -1, y: 01, label: a)
 4:   (x: 09, y: 01, label: a)						 4:   (x: 09, y: 01, label: a)
 5:   (x: 01, y: 01, label: f)						 5:   (x: 01, y: 01, label: f)
 6:   (x: 00, y: 00, label: a)						 6:   (x: 00, y: 00, label: a)
 7:   (x: -1, y: -5, label: a)						 7:   (x: -1, y: -5, label: a)
 8:   (x: 00, y: 00, label: a)						 8:   (x: 00, y: 00, label: a)
 9:   (x: 01, y: 00, label: a)						 9:   (x: 01, y: 00, label: a)
10:   (x: 00, y: 00, label: k)						10:   (x: 00, y: 00, label: k)
11:   (x: -1, y: -5, label: a)						11:   (x: -1, y: -5, label: a)
12:   (x: 06, y: 06, label: a)						12:   (x: 06, y: 06, label: a)
13:   (x: 01, y: 01, label: b)						13:   (x: 01, y: 01, label: b)
14:   (x: 00, y: 01, label: b)						14:   (x: 00, y: 01, label: b)
15:   (x: -1, y: -5, label: a)						15:   (x: -1, y: -5, label: a)
------------- 								------------- 
Test 9 Failed: incorrect answer					     |	Test 9 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 0 ,  Expected: 2 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 8 		     <
--------------------------------
** Test 10: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 10, y: 19, label: hello)					 0:   (x: 10, y: 19, label: hello)
 1:   (x: 20, y: 29, label: goodbye)					 1:   (x: 20, y: 29, label: goodbye)
 2:   (x: 30, y: 39, label: hello)					 2:   (x: 30, y: 39, label: hello)
 3:   (x: 40, y: 49, label: goodbye)					 3:   (x: 40, y: 49, label: goodbye)
 4:   (x: 50, y: 59, label: hello)					 4:   (x: 50, y: 59, label: hello)
 5:   (x: 40, y: 49, label: hello)					 5:   (x: 40, y: 49, label: hello)
 6:   (x: 30, y: 39, label: goodbye)					 6:   (x: 30, y: 39, label: goodbye)
 7:   (x: 20, y: 29, label: hello)					 7:   (x: 20, y: 29, label: hello)
 8:   (x: 10, y: 19, label: goodbye)					 8:   (x: 10, y: 19, label: goodbye)
 9:   (x: 22, y: 33, label: hello)					 9:   (x: 22, y: 33, label: hello)
------------- 								------------- 
Test 10 Failed: incorrect answer				     |	Test 10 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 1 ,  Expected: 6 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 0 		     <
--------------------------------
** Test 11: 
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output). Output difference:-
Input array: 								Input array: 
 0:   (x: 10, y: 19, label: hello)					 0:   (x: 10, y: 19, label: hello)
 1:   (x: -20, y: -29, label: hello)					 1:   (x: -20, y: -29, label: hello)
 2:   (x: -30, y: -39, label: hello)					 2:   (x: -30, y: -39, label: hello)
 3:   (x: -40, y: -9, label: hello)					 3:   (x: -40, y: -9, label: hello)
 4:   (x: -50, y: -59, label: hello)					 4:   (x: -50, y: -59, label: hello)
 5:   (x: -40, y: -49, label: hello)					 5:   (x: -40, y: -49, label: hello)
 6:   (x: -30, y: -39, label: hello)					 6:   (x: -30, y: -39, label: hello)
 7:   (x: -20, y: -29, label: hello)					 7:   (x: -20, y: -29, label: hello)
 8:   (x: -10, y: -19, label: hello)					 8:   (x: -10, y: -19, label: hello)
 9:   (x: 19, y: 10, label: hello)					 9:   (x: 19, y: 10, label: hello)
------------- 								------------- 
Test 11 Failed: incorrect answer				     |	Test 11 Passed
See below for the expected answer.				     |
 (in_quadrant1) Your answer: 1 ,  Expected: 2 			     <
 (not_in_quadrant1) Your answer: 0 ,  Expected: 8 		     <
--------------------------------
!!section assess

!!perftab	** PERFORMANCE ANALYSIS **

Test  1 (0.25)	 ..  !!FAILed (-0.25)
Test  2 (0.25)	 ..  !!FAILed (-0.25)
Test  3 (0.5)	 ..  !!PASSed
Test  4 (0.5)	 ..  !!FAILed (-0.5)
Test  5 (0.5)	 ..  !!FAILed (-0.5)
Test  6 (0.5)	 ..  !!FAILed (-0.5)
Test  7 (0.5)	 ..  !!FAILed (-0.5)
Test  8 (0.5)	 ..  !!FAILed (-0.5)
Test  9 (0.5)	 ..  !!FAILed (-0.5)
Test 10 (0.5)	 ..  !!FAILed (-0.5)
Test 11 (0.5)	 ..  !!FAILed (-0.5)

!!perfmark	** TOTAL PERFORMANCE MARK:    0.5/5

!!marktab	**  MARKER'S  ASSESSMENT  **

!!finalmark	**  FINAL  ASSIGNMENT  MARK:	2/5

5206032	Nguyen, Dan Huy                        	3768/1 MTRNAH       

Autocommitted by jashankj:cs1511 at Sun Nov 11 15:41:37 AEDT 2018
