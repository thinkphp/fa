/**
 * Author: Adrian Statescu <mergesortv@gmail.com> http://adrianstatescu.com
 * Description: Quadratic Equation Solver in ANSI C Language
 * MIT License 
 */
#include <stdio.h>
#define FIN "quadratic.in"
#define FOUT "quadratic.out"
#define MAXEQ 100

int main() {

    int i,j//iterators for loops  
        ,n;//number of equations

    float mat[MAXEQ][3], delta
          ,a, b, c,
          x1, x2; 

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
 
    scanf("%d", &n);

    for(i = 0; i < n; ++i) {

        for(j = 0; j < 3; ++j) {

            scanf("%f", &mat[i][j]);
        }
    }

    for(i = 0; i < n; ++i) {

        a = mat[i][0];
        b = mat[i][1];
        c = mat[i][2];

        printf("Quadratic equation %d:\n", (i + 1));
        printf("%.2fx^2 + %.2fx + %.2f\n", a, b, c);

        delta = b * b - 4 * a * c;
        
        if(delta < 0 ) {

               printf("Do not have real roots! Only in complex plan!");   
               printf("\n");   

        } else if(delta == 0) {

               x1 = x2 = (-b) / (2 * a);

               printf("x1 = x2 = %.2f\n", x1);   

        } else {

               x1 = (-b + sqrt(delta)) / (2 * a);              
               x2 = (-b - sqrt(delta)) / (2 * a);
               printf("x1 = %.2f, x2 = %.2f\n", x1, x2);   

        }   

               printf("\n");           
    }
       
    fclose(stdin); 
    fclose(stdout);

 return(0);
}