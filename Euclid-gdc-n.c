#include <stdio.h>

int GDCRecursive(int a, int b) {

    if(b == 0) return a;

    else return GDCRecursive(b, a % b);   
};

int GDCDivision(int a, int b) {

    int r;

    while( b != 0 ) {
           r = a % b;
           a = b;
           b = r;
    }
    return a;
};


int GDCSubstraction(int a, int b) {

    while( a != b ) {
         if(a > b) {
            a -= b;
         } else if(b > a) {
            b -= a;
         }
    }

    return a;
};

int Euclid(int a, int b) {

    int r;

    while( b != 0 ) {
           r = a % b;
           a = b;
           b = r;
    }
    return a;
};



int DivideEtImpera(int *arr, int lo, int hi) {
     
    if(lo < hi) {

       int m = (lo+hi)>>1;

           return Euclid(DivideEtImpera(arr, lo, m), DivideEtImpera(arr, m + 1 , hi));         
    }

    return arr[ lo ]; 
};

int GDCArray(int *arr, int len) {

    return DivideEtImpera(arr, 0, len - 1);

};

int GDCArrayRec(int *arr, int len) {

    if(len == 1) return arr[ 0 ];

       else return Euclid(GDCArrayRec(arr, len - 1), arr[len - 1]);
};


int main( void ) {

 int a = 10, 
     b = 3;

 int arr[] = {20, 100, 40, 200, 80};

 printf("Euclid(%d, %d) = %d; Should be 1;\n", a, b, GDCRecursive(a, b));
 printf("Euclid(%d, %d) = %d; Should be 1;\n", a, b, GDCDivision(a, b));
 printf("Euclid(%d, %d) = %d; Should be 1;\n", a, b, GDCSubstraction(a, b));
 printf("Euclid(arr) = %d; Should be 20;\n", GDCArray(arr, sizeof(arr)/sizeof(int)));
 printf("Euclid(arr) = %d; Should be 20;\n", GDCArrayRec(arr, sizeof(arr)/sizeof(int)));

 return(0);
};