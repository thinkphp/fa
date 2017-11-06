/**
 *  Let's read an integer n. Determine p maximum such that 3^p <= n with n >= 3
 */
#include <stdio.h>

int main() {

    int n, 
        p, 
        trois;

    printf("n=");
    scanf("%d", &n); 

    p = 0;
    trois = 1;

    while(trois <= n) {

          trois = trois * 3;
          p = p + 1;
    }
    
    printf("%d",p-1);

 return(0);
};