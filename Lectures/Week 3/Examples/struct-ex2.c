// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 

#include <stdio.h>
#include <string.h>

struct student {
      int zid;
      char name[64];
      double lab_marks[10];
      double assignment1_mark;
      double assignment2_mark;
};

typedef struct student student_t;

student_t comp1511_students[100];
  
  
void printStudent(student_t  s) {

    printf("zid: %d | ", s.zid);
    printf("name: %s\n", s.name);

}  

int main(void) {

   
    comp1511_students[0].zid = 341276;
    strcpy(comp1511_students[0].name, "John");
    comp1511_students[0].assignment2_mark = 56.8; 
    comp1511_students[0].assignment1_mark = 79;     
    
   
    comp1511_students[1].zid = 7881234;
    strcpy(comp1511_students[1].name, "Rita");
    comp1511_students[1].assignment2_mark = 99; 
    comp1511_students[1].assignment1_mark = 45.7;     

    printStudent(comp1511_students[1]);
    printStudent(comp1511_students[0]);    

    return 0;
}
