#include <stdio.h>

typedef struct fraction {

       int num,
           den; 
} Fraction;

void readFraction(Fraction *f) {

     printf("Numerator:");
     scanf("%d", &f->num);

     printf("Denominator:");
     scanf("%d", &f->den);
};

int Euclid(int a, int b) {

     int r;

     while( b ) {
            r = a % b;
            a = b;
            b = r;  
     }
     return a;
}

void simplify(Fraction *f) {

     int r;
  
         r = Euclid(f->num, f->den);

         f->num /= r; 
         f->den /= r;
};

void prodFractions(Fraction f1,Fraction f2,Fraction *fp) {

     fp->num = f1.num * f2.num;

     fp->den = f1.den * f2.den;

     simplify( fp ); 
}

int main() {

    Fraction f1, f2, fp;

    printf("Fraction 1\n");
    readFraction(&f1);
    printf("Fraction 2\n");
    readFraction(&f2);

    prodFractions(f1,f2,&fp);

    printf("\nOutput:\n");
    printf(" %d / %d * %d / %d = %d / %d",f1.num, f1.den, f2.num, f2.den, fp.num, fp.den);

 return(0);

};