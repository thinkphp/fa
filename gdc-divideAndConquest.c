#include <stdio.h>
#include <malloc.h>
#include <time.h>

int gcc(int a, int b) {

    if(b == 0) return a;

    return gcc(b, a % b);
};

int divetimp(int *arr, int li, int ls){

     int m,a,b;

     if(li < ls) {

        m = (li+ls)>>1;          

        a = divetimp(arr,li,m);

        b = divetimp(arr,m+1,ls);

        return gcc(a, b);
     }

     return arr[ li ];
}

int main() {

    int *arr;
    int i, n = 11, r;

    srand(time(NULL));

    arr = (int*)malloc(sizeof(int) * n);  

    for(i = 0; i < n; ++i) r = rand()%100, arr[ i ] = r;

    for(i = 0; i < n; ++i) printf("%d ", arr[ i ]);

    printf("gcc=%d", divetimp(arr, 0, n - 1));    

    free(arr);
 
    return(0);
}