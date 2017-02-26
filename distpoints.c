#include <stdio.h>
#include <math.h>
#define FIN "distpoints.in"

typedef struct Point {
  double x, 
         y;
} Point;

double Dist(Point p1, Point p2) {

       return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
};



int main() {

Point p0,
      p1,
      p;
int i,
    n; 

double dist, tempDist;

freopen(FIN, "r", stdin);

scanf("%lf %lf", &p0.x, &p0.y);

scanf("%d", &n);

scanf("%lf %lf", &p1.x, &p1.y);

dist = Dist(p0, p1);

for(i = 2; i <= n; ++i ) {

     scanf("%lf %lf", &p.x, &p.y);

     tempDist = Dist(p0, p);

     if(tempDist < dist) dist = tempDist, p1 = p;      
}

printf("The nearest point has the coords (%.2lf, %.2lf)\n and the distance = %.2lf", p1.x, p1.y, dist);

 return(0);
}