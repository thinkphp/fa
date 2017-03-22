/**
 *  Approximate the function sin with series Taylor.
 *
 *  sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ....(-1)^n+1*x^(2n+1)/(2n+1)!;
 *  
 *
 */

#include <stdio.h>
#include <math.h>

int fact(int n) {

    if(n == 0) return 1;

       else return n * fact( n -1);
}

float myPow(int a, int b) {

      int i, 

          p = 1;

      for(i = 1; i <= b; ++i) p *= a;

   return p;
}

double mySin(double x) {

    int i = 2;

    float EPS = 0.00001;

    double term1 = x, 

           term2 = x - (float) myPow(x, 3) / fact(3.0);

          while( fabs(term1-term2) >= EPS ) {

                 term1 = term2;
    
                 term2 += pow(-1, i) * (double) myPow(x, (2*i+1)) / fact(2*i+1);
              
                 i++;
          }        
         
       
    return term2;  
}

int main() {

    double x;

    printf("x=");

    scanf("%lf", &x);

    printf("sin(%.2f) = %.10f\n", x , sin( x ));

    printf("sin(%.2f) = %.10f", x , sin( x )); 

 return 0;
}