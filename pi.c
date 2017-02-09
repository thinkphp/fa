/**
 *  Adrian Statescu <mergesortv@gmail.com> http://adrianstatescu.com http://thinkphp.ro
 *  Computes PI approximation
 *  Infinite Serie 1-1/3+1/5-1/7+1/9....
 */
#include <stdio.h>

int main() {

    float t1, t2, eps;

    int i, sign;

    t1 = 1.0;

    t2 = 1.0 - 1.0/(float)1.0/3.0;

    sign = 1;

    i = 5;

    printf("EPSILON=");

    scanf("%f", &eps);

    while( 4 * (t1 > t2 ? t1 - t2 : t2 - t1) >= eps ) {

           t1 = t2;
 
           t2 += sign * (float)1.0/i;

           sign *= -1;

           i+=2;                    
    }    

    printf("PI with precision %f  = %.20f", eps, 4 * t2);
}