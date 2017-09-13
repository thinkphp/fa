#include <stdio.h>

#define SIZE 5

int _GDC(int a, int b) {

    int r;
    while(b!=0) {
      r = a % b;
      a = b;
      b = r;  
    } 
    return a;
}

int _divideEtImpera(int lo, int hi, int arr[]) {

    int mi, a, b;

    if(lo < hi) {

           mi = (lo+hi)>>1;

               a = _divideEtImpera(lo, mi, arr);

               b = _divideEtImpera(mi+1, hi, arr);

           return _GDC(a,b);
    } 

    return arr[lo];
}

int GDC(int arr[], int n) {

         return _divideEtImpera(0, n - 1, arr); 
};

int main() {

    int arr[] = {100,40,20,50,90};
    
    printf("%d", GDC(arr, sizeof(arr)/sizeof(int)));
  
 return(0);
};