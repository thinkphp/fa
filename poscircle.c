/**
 Input: C(x,y,r),P(x0,y0);
 Output: Interior or Exterior C P(x0,y0) 
 */

#include <stdio.h>
#include <math.h>
#define FIN "poscircle.in"
#define FOUT "poscircle.out"

int main() {

 float x, 
       y,
       r,
       x0,
       y0;

 double d;

 freopen(FIN, "r", stdin);
 freopen(FOUT, "w", stdout);

 scanf("%f %f %f", &x, &y, &r);
 scanf("%f %f", &x0, &y0);

 printf("C(%.2f,%.2f,%.2f)\n", x, y, r);

 printf("P(%.2f,%.2f)", x0, y0);

 d = sqrt((x-x0)*(x-x0) + (y-y0)*(y-y0));

 d -= r;

 if(d == 0) printf("\nThe point is on Circle; Le point est sur le circle"); 

       else if(d < 0) printf("\nThe point is inside the circle.");
 
            else printf("\nThe point is outside the circle.");

 fclose( stdin );
 fclose( stdout );

 return(0);
}