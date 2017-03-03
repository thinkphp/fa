/**
 *
 *  C program to compute the value of PI using formula's Leibniz.
 *  PI approximate 4 ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11...
 */

#include <stdio.h>
#define EPS 0.0000001

int main() {

 double v1,v2;

 int i = 5;

 int sign = 1;

 v1 = 1;

 v2 = 1 - (double)1/3;

 while(4 * ((v1 > v2) ? (v1 - v2) : (v2 - v1)) >= EPS ) {

        v1 = v2;

        v2 += sign * (double) 1 / i;

        sign *= -1;

        i += 2;
 }

 printf("Approximate PI ---> %g", 4 * v2);

 return(0);
}