/**
 * Adrian Statescu <mergesortv@gmail.com> http://adrianstatescu.com http://thinkphp.ro
 * Euler's number.Base of the natural logarithm.
 * E ~= 1+1/1!+1/2!+1/3!+1/4!+1/5!...
 */
#include <stdio.h>

int fact(int n) {

    if(n == 0) return 1;

    else return n * fact(n-1);  
}

int main() {

    float t1,
          t2, 
          EPS;

    int i;

    t1 = 1.0;

    t2 = 1.0 + (float)1.0/1.0;

    i = 2;

    printf("EPSILON=");

    scanf("%f", &EPS);

    while( (t2-t1) >= EPS ) {

         t1 = t2;

         t2 += (float)1.0/fact(i);

         i++; 
    }

    printf("Euler's Number with precision %f  = %.20f", EPS, t2); 
}
