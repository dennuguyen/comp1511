Session: 18s2
Assignment: week05_q3  Submission ID: 5206032


Your submission has been marked. + /usr/bin/less -m /import/ravel/4/z5206032/cs1511.week05_q3.mrk

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
                                                                 ^

S 0     Thu Aug 23 13:00:42 2018        z5206032 all q3 0

Mon Sep 10 07:45:16 2018                ## weill.orchestra.cse.unsw.EDU.AU ##
!!section listing
-rw------- cs1511exam/cs1511exam 780 2018-08-23 13:00 maxBelow.c
C files ........
maxBelow.c
dos2unix: converting file maxBelow.c to Unix format ...

===============================================================================
-rw-r--r-- 1 cs1511 cs1511 780 Sep 10 07:45 maxBelow.c
===============================================================================

     1
     2  #define MAX_NUMBER 99999
     3
     4  // Function returns maximum value from a given array that is less
     5  // than the limit value. If there are no values less than limit
     6  // then return limit value.
     7  int maxBelow(int a[], int size, int limit){
     8
     9      int i = 0;
    10      int j = 0;
    11      int belowLimit[MAX_NUMBER];
    12
    13      // considers all numbers below the limit value.
    14      while (i < size) {
    15          if (a[i] < limit) {
    16              belowLimit[j] = a[i];
    17              j++;
    18          }
    19          i++;
    20      }
    21
    22      int size_j = j;
    23      int placeholder;
    24
    25      j = 0;
    26      // get maximum number below the limit value.
    27      while (j < size_j - 1) {
    28          if (belowLimit[j + 1] > belowLimit[j]) {
    29              placeholder = belowLimit[j + 1];
    30          }
    31          j++;
    32      }
    33
    34      return placeholder;
    35  }
    36
    37

!!section tests
** Test 1:
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output ). Output difference:-
-------------                                                   -------------
Test 1 Failed!, see below for the expected answer.         |    Test 1 Passed
  maxBelow, expected: 4, your answer: -1094795586          <

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
** Test failed (difference in output: (<) Student output, (>) Expected output ). Output difference:-
-------------                                                   -------------
Test 4 Failed!, see below for the expected answer.         |    Test 4 Passed
  maxBelow, expected: 11, your answer: 10                  <

--------------------------------
** Test 5:
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output ). Output difference:-
-------------                                                   -------------
Test 5 Failed!, see below for the expected answer.         |    Test 5 Passed
  maxBelow, expected: -5, your answer: -23                 <

--------------------------------
** Test 6:
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output ). Output difference:-
-------------                                                   -------------
Test 6 Failed!, see below for the expected answer.         |    Test 6 Passed
  maxBelow, expected: 20, your answer: -1094795586         <

--------------------------------
!!section assess

!!perftab       ** PERFORMANCE ANALYSIS **

Test  1 (0.6)    ..  !!FAILed (-0.6)
Test  2 (0.7)    ..  !!PASSed
Test  3 (0.7)    ..  !!PASSed
Test  4 (1)      ..  !!FAILed (-1)
Test  5 (1)      ..  !!FAILed (-1)
Test  6 (1)      ..  !!FAILed (-1)

!!perfmark      ** TOTAL PERFORMANCE MARK:    3/5      <== mark altered (original mark was 1.4)

!!marktab       **  MARKER'S  ASSESSMENT  **

!!finalmark     **  FINAL  ASSIGNMENT  MARK:    3/5

5206032 Nguyen, Dan Huy                         3768/1 MTRNAH


Marked by z5165390 on Thu Sep 13 08:40:07 2018

