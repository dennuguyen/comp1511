// The following is a demo version,  this release 
// may be incomplete and/or incorrect
// Please watch the corresponding lecture video for clarifications. 


#include <stdio.h>

int main(void) {

    char city[7] = {'S', 'y', 'd', 'n', 'e', 'y', '\0' };
    
    // Alternatively    
    char myCity[] = "Great Sydney!" ;
    
    printf("City name is %s \n", city);
    printf("My city name is %s \n", myCity);    
     

    return 0;
}
