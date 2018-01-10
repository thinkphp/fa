#include <stdio.h>

typedef struct fraction {
       int num, 
           den;
} Fraction;

void readFraction(Fraction *f) {
   
     printf("Numerator -> ");
     scanf("%d", &f->num);

     printf("Denominator -> ");
     scanf("%d", &f->den);

};

int Euclid(int a, int b) {

     int aux;

     while( b ) {

            aux = a % b;
            a = b;
            b = aux;                
     }

     return a;
};

void simplify(Fraction *f) {

     int d;
     d = Euclid(f->num , f->den);
     f->num /= d;  
     f->den /= d;
};


int sumFractions(Fraction f1, Fraction f2, Fraction *fs) {

     fs->num = f1.num * f1.den + f2.num * f1.den;
     fs->den = f1.den * f2.den;

     simplify( fs );  
     return 0;
};

int main() {

    Fraction f1, 
             f2, 
             fs;

    printf("Fraction 1:\n");
    readFraction(&f1);
    printf("Fraction 2:\n");
    readFraction(&f2);
    sumFractions(f1,f2,&fs);
 
    printf("%d / %d + %d / %d = %d / %d", f1.num, f1.den, f2.num, f2.den, fs.num, fs.den);
 return(0);
};