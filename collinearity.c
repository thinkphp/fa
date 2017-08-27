/*
 * Prove that the points A (1, 1), B (-2, 7) and (3, -3) are collinear.
 *
 *  1.solution:
 *
 *  |x1 y1 1 |
 *  |x2 y2 1 | = 0;
 *  |x3 y3 1 |
 *
 *  2.solution:
 *
 *  y1 - y2   y2 - y3
 *  ------- = -------
 *  x1 - x2   x2 - x3
 * 
 *  3. solution
 *  dist(A,B) + dist(B,C) = dist(A,C)
 */

#include <stdio.h>
#include <math.h>
#define SIZE 3

typedef struct point {

    int x, //abscise
        y; //ordonate
} Point;

Point vec[SIZE];

int dist(Point A, Point B) {

    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));           
};

int findDet(int m11, int m12, int m13, int m21, int m22, int m23, int m31, int m32, int m33) {

    return m11 * m22 * m33 + m12 * m23 * m31 + m13 * m21 * m32 

         - m13 * m22 * m31 - m11 * m23 * m32 - m12 * m21 * m33 ;
};

int main() {

    int i;

    for(i = 0; i < 3; ++i) {

        printf("Point %d -> \n", i + 1);

        printf("x = ");
        scanf("%d", &vec[i].x);
        printf("y = ");
        scanf("%d", &vec[i].y);
    }

//first solution

    if(findDet(vec[0].x, vec[0].y, 1, vec[1].x, vec[1].y, 1, vec[2].x, vec[2].y, 1) == 0) printf("Solution 1 -> The Points are Collinears!");

              else     printf("Not Collinears!!!");

//second solution

  if(vec[0].x == vec[1].x || vec[2].x == vec[3].x) {

            if(vec[0].x == vec[3].x) {
      
                        printf("Solution 1 -> Collinears!");
            } else {

                        printf("Solution 1 -> Not Collinears!");
            }     
  } else {

         if( ( (vec[0].y - vec[1].y)/(vec[0].x - vec[1].x) ) == ( (vec[1].y - vec[2].y)/(vec[1].x - vec[2].x) ) ) printf("\nSolution 2 -> Collinears!");

                             else                     printf("Not Collinears!");
  } 

 //third solution
  
  if( (dist(vec[0],vec[1]) + dist(vec[1], vec[2])) == dist(vec[0],vec[2]) ) printf("\nSolution 3 -> Collinears");

                           else printf("\nSolution 3 -> Not Collinears!"); 

  printf("\n%d", dist(vec[0],vec[1]));
  printf("\n%d", dist(vec[1],vec[2]));
  printf("\n%d", dist(vec[0],vec[2]));
 return(0);
};