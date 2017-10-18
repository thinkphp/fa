#include <stdio.h>
#include <math.h>
#define SIZE 50

typedef struct TypePoint {
       float x,//abscise
             y;//ordonate
} TPoint;

typedef struct TypeCircle {

       TPoint O;
       float R;

} TCircle;

float distance(TPoint p1, TPoint p2) {

      return (float)sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ); 
};

int belong(TCircle C, TPoint p) {

    float dist = distance(C.O, p);

    if( dist < C.R ) { return 1; }

        else        { return 0; }
}

TCircle circles[ SIZE ];
TPoint p;

int main( void ) {

    int i, //for iterator
        n; //number of circles

    printf("Number of circles: ");
    scanf("%d", &n);

    for(i = 0; i < n; ++i) {

        printf("Circle: ", (i+1));

        printf("Enter C(O(x,y),R) = ");

        scanf("%f %f %f", &circles[i].O.x, &circles[i].O.y, &circles[i].R); 
    } 

    printf("Enter coords for the Point = ");

    scanf("%f %f", &p.x, &p.y); 

    printf("\nOutput: \n");

    for(i = 0; i < n; ++i) {

        if( belong(circles[ i ], p) ) {            

            printf("%d -> C(%3.3f, %3.3f, %3.3f) \n",(i + 1), circles[i].O.x, circles[i].O.y, circles[i].R);
        }
    }
    
    return(0); 
};