/**
 * Adrian Statescu <mergesortv@gmail.com>
 * Derivatives and Polynomials.
 * MIT License
 */
#include <stdio.h>
#define MAXN 500

void readPolynom(int *n, int vec[]) {

     int i;

     printf("Grade of Polynome:\n->>");
     scanf("%d", n);

     printf("Enter the coefs: \n");
     for(i = 0; i <= *n; ++i) {

         scanf("%d", &vec[ i ]);
     }
     
}

void writePolynome(int *n, int vec[], int flag) {

     int i;
  
     if( flag == 0 ) {

          printf("P(x) = ");

     } else {

          printf("P'(x) = ");
     }

     printf("%d ", vec[ 0 ]);

     for(i = 1; i <= *n; ++i) {

         printf("+ %dx^%d ", vec[ i ], i);
     }

     printf("\n");
}

void derivatePolynome(int *n,int vec[]) {

     int i; 

     vec[ 0 ] = vec[ 1 ];

     for(i = 1; i <= *n; ++i) {

         vec[ i ] = vec[ i + 1 ] * (i + 1);
     }  

     (*n)--;
}

double performeDerivate(int *n, int vec[], double x) {

       int i;

       double valToComputeDer = vec[ 0 ],

              x_aux = 1;

       for(i = 1; i <= *n; ++i) {

           x_aux *= x;

           valToComputeDer += vec[ i ] * x_aux;
       }

    return valToComputeDer;
}

int main() {

    int n,
        p[ MAXN ]; 

    float x;

    readPolynom(&n, p);
    writePolynome(&n, p, 0); 
  
    derivatePolynome(&n, p);
    writePolynome(&n, p, 1); 

    printf("Value Perform Derivate\n->>");
    scanf("%f", &x);

    printf("P'(%.3f) = %.20f ", x, performeDerivate(&n,p,x));

return(0); 
}