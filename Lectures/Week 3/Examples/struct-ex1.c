
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

    student_t  s1;
    
    s1.zid = 341276;
    strcpy(s1.name, "John");
    s1.assignment2_mark = 56.8; 
    s1.assignment1_mark = 79;     
    
    student_t  s2;
    
    s2.zid = 7881234;
    strcpy(s2.name, "Rita");
    s2.assignment2_mark = 99; 
    s2.assignment1_mark = 45.7;     

    printStudent(s2);
    printStudent(s1);    

    return 0;
}
