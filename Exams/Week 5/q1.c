Session: 18s2
Assignment: week05_q1  Submission ID: 5206032


Your submission has been marked. + /usr/bin/less -m /import/ravel/4/z5206032/cs1511.week05_q1.mrk

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

S 0     Thu Aug 23 13:00:13 2018        z5206032 all q1 0

Sat Sep 08 16:45:13 2018                ## weber.orchestra.cse.unsw.EDU.AU ##
!!section listing
-rw------- cs1511exam/cs1511exam 216 2018-08-23 13:00 getFlag.c
C files ........
getFlag.c
dos2unix: converting file getFlag.c to Unix format ...

===============================================================================
-rw-r--r-- 1 cs1511 cs1511 216 Sep  8 16:45 getFlag.c
===============================================================================

     1
     2  // Function returns 0, 1, 2 based on values of x and y.
     3
     4  int getFlag(int x, int y){
     5
     6      if (x < 50 && y > 70) {
     7          return 1;
     8      } else if (x <= 10 || x >= 90) {
     9          return 2;
    10      }
    11
    12      return 0;
    13  }
    14
    15

!!section tests
** Test 1:
--------------------------------
** Test failed (difference in output: (<) Student output, (>) Expected output ). Output difference:-
-------------                                                   -------------
Test 1 Failed!, see below for the expected answer.         |    Test 1 Passed
  x is 5, y is 120                                         <
  getFlag, expected: 2, your answer: 1                     <

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
!!section assess

!!perftab       ** PERFORMANCE ANALYSIS **

Test  1 (0.6)    ..  !!FAILed (-0.6)
Test  2 (0.7)    ..  !!PASSed
Test  3 (0.7)    ..  !!PASSed
Test  4 (0.5)    ..  !!PASSed
Test  5 (0.5)    ..  !!PASSed
Test  6 (0.5)    ..  !!PASSed
Test  7 (0.5)    ..  !!PASSed
Test  8 (0.5)    ..  !!PASSed
Test  9 (0.5)    ..  !!PASSed

!!perfmark      ** TOTAL PERFORMANCE MARK:    4.4/5

!!marktab       **  MARKER'S  ASSESSMENT  **

!!finalmark     **  FINAL  ASSIGNMENT  MARK:    4.4/5

5206032 Nguyen, Dan Huy                         3768/1 MTRNAH





Marked by z5165390 on Tue Sep 11 19:08:50 2018
