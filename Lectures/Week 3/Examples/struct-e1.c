// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


#include <stdio.h>

struct student {
      int zid;
      char name[64];
      double lab_marks[10];
      double ass1;
      double ass2;
};

typedef struct student student_t;

student_t sts[100];
  
  
void printStu( student_t s) {

    printf("from function: zid is %d \n", s.zid);    

} 
  

int main(void) {
    
    sts[0].zid = 45321;
    sts[0].ass1 = 67.9;
 
    student_t  s2; 
    s2.zid = 565465464;
    s2.ass1 = 99;    
    s2.lab_marks[1] = 12; 
    
    
    
    printStu(sts[0]);
    printStu(s2);
    
    
       


    return 0;
}
