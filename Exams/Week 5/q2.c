Session: 18s2
Assignment: week05_q2  Submission ID: 5206032


Your submission has been marked. + /usr/bin/less -m /import/ravel/4/z5206032/cs1511.week05_q2.mrk

!!section banner
#######  #####    ###    #####    ###    #####   #####
#       #     #  #   #  #     #  #   #  #     # #     #
#             # # #   # #       # #   #       #       #
 #####   #####  #  #  # ######  #  #  #  #####   #####
      # #       #   # # #     # #   # #       # #
#     # #        #   #  #     #  #   #  #     # #
 #####  #######   ###    #####    ###    #####  #######

5206032 Nguyen, Dan Huy                         3768/1 MTRNAH

Submissions:-

S 0     Thu Aug 23 13:00:34 2018        z5206032 all q2 0

Mon Sep 10 17:56:30 2018                ## weber.orchestra.cse.unsw.EDU.AU ##
!!section listing
-rw------- cs1511exam/cs1511exam 567 2018-08-23 13:00 countDecreasing.c
C files ........
countDecreasing.c
dos2unix: converting file countDecreasing.c to Unix format ...

===============================================================================
-rw-r--r-- 1 cs1511 cs1511 567 Sep 10 17:56 countDecreasing.c
===============================================================================

     1  #include <stdio.h>
     2
     3  #define MAX_NUMBER 99999
     4
     5  int main (void) {
     6
     7      int list[MAX_NUMBER];
     8      int i = 0;
     9      int noRead = 1;
    10
    11      // get list of integers
    12      while (noRead == 1) {
    13          printf("Enter number: ");
    14          noRead = scanf("%d", &list[i]);
    15          i++;
    16      }
    17
    18      int size = i;
    19      int count = 0;
    20
    21      i = 0;
    22      // check decreasing
    23      while (i < size - 1) {
    24          if (list[i] > list[i + 1]) {
    25              count++;
    26          }
    27          i++;
    28      }
    29
    30      count--;
    31      printf("\nCount of Decreasing: %d\n", count);
    32
    33      return 0;
    34  }

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
!!section assess

!!perftab       ** PERFORMANCE ANALYSIS **

Test  1 (0.6)    ..  !!PASSed
Test  2 (0.7)    ..  !!PASSed
Test  3 (0.7)    ..  !!PASSed
Test  4 (1)      ..  !!PASSed
Test  5 (1)      ..  !!PASSed
Test  6 (1)      ..  !!PASSed

!!perfmark      ** TOTAL PERFORMANCE MARK:    5/5

!!marktab       **  MARKER'S  ASSESSMENT  **

!!finalmark     **  FINAL  ASSIGNMENT  MARK:    5/5

5206032 Nguyen, Dan Huy                         3768/1 MTRNAH



Marked by z5165390 on Wed Sep 12 12:49:20 2018
