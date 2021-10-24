// Week 3 Lab
// Program that reads an integer, n, then draws that many boxes inside each
// other using '#'.
// 
// Dan Nguyen (z5206032)
// 2018/08/07
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>

int main(void) {
    
    int box, side = 0;
    int limit1, limit2 = 0;
    int m, n;
    
    printf("How many boxes: ");
    scanf("%d", &box);
    
    // Simple pattern between number of boxes and side length.
    box--;
    side = box * 4 + 3;
    
    // Visually, limit1 starts at the left and limit2 starts at the right.
    limit1 = 1;
    limit2 = side;
    
    // Logic!
    // 
    // A box of hash around a box of space around a box of hash...
    // 
    // Two limits which ++ and -- respectively with every row, m,
    // where the column, n, is in the range between these two limits.
    // 
    // Odd rows will have hashes and even rows will have spaces.
    //
    // Same logic applies to columns
    
    m = 1;
    
    while(m <= side) {
        
        n = 1;
        
        while(n <= side) {
            
        // Algorithm for horizontal sides of boxes.
            // prints top half of boxes in 'V' shape.
            if ((limit1 <= n && n <= limit2) && (m % 2 == 0)) {
                printf(" ");
            } else if ((limit1 <= n && n <= limit2) && (m == limit1 ||
                m == limit2)) {
            
                printf("#");
            
            // prints bottom half of boxes in '^' shape
            } else if ((limit2 <= n && n <= limit1) && (m % 2 == 0)) {
                printf(" ");
            } else if ((limit2 <= n && n <= limit1) && (m == limit1 ||
                m == limit2)) {
                
                printf("#");
                
        // Algorithm for vertical sides of boxes.
            //prints top half of sides of boxes in triangular shape.
            } else if ((limit1 <= m && m <= limit2) && (n % 2 == 0)) {
                printf(" ");
            
            // prints bottom half of sides of boxes in upside down triangle.
            } else if ((limit2 <= m && m <= limit1) && (n % 2 == 0)) {
                printf(" ");
            
        // filler.
            } else {
                printf("#");
            }
            
            n++;
        }
        
        printf("\n");
        m++;
        
        // limit1 starts at n = 1 and approaches right.
        limit1++;
        
        // limit2 starts at n = side and approaches left.
        limit2--;
    }

    return 0;
}