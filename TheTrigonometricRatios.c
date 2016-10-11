/*
    Hackerrank 

    The Trigonometric Ratios Problem

    https://www.hackerrank.com/challenges/trignometric-ratios/leaderboard/2
 */
#include <stdio.h>
#include <math.h>

double fact(int n) {

    if(n == 0) return 1;

       else return n * fact( n - 1);
}

double myFabs(double a, double b) {

      if(a > b) return a - b;

           else 

                return b - a;
}

double myPow(double a, double b) {

      int i;

      double p = 1;

      for(i = 1; i <= b; ++i) p *= a;

   return p;
}

double mySin(double x) {

    int i = 2;

    double EPS = 0.001;

    double term1 = x, 

           term2 = x - (float) myPow(x, 3) / fact(3.0);

          while( myFabs(term1, term2) >= EPS ) {

                 term1 = term2;
    
                 term2 += (double) pow(-1, i) * (double) myPow(x, (2*i+1)) / fact(2*i+1);
              
                 i++;
          }        
         
       
    return term2;  
}


double myCos(float x) {

    int i = 2;

    double EPS = 0.000001;

    double term1 = 1, 

          term2 = term1 - (double) myPow(x, 2) * 1.0/ fact(2);         

          while( myFabs(term1, term2) >= EPS ) {

                 term1 = term2;
    
                 term2 += (double) pow(-1, i) * (double) myPow(x, 2 * i) * 1.0 / fact(2 * i);
              
                 i++;
          }        

       
    return term2;  
}

int main() {

    double x;
    printf("x=");
    scanf("%lf", &x);
    printf("sin(%.3lf) = %.3lf\n", x , sin( x ));
    printf("cos(%.3lf) = %.3lf\n", x , cos( x ));

 return (0);
}

