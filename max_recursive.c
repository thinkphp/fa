#include <stdio.h>

int max(int a, int b) {

    return a > b ? a : b;
};

int MAXRecursive(int *arr, int len) {
    
    if(len == 1) return arr[ 0 ];  

    else return max(MAXRecursive(arr, len - 1), arr[len - 1]);
};

int MAXIterative(int *arr, int len) {

    int i,

        max = arr[0];

    for(i = 1; i < len; ++i) {

        if(arr[ i ] > max) max = arr[ i ];
    }

    return max; 
};

int main( void ) {

 int arr[] = {1, 2, 7, 3, 4, -1, 991, 33, 331};
 printf("%d\n", MAXRecursive(arr, sizeof(arr)/sizeof(int)));
 printf("%d", MAXIterative(arr, sizeof(arr)/sizeof(int)));

 return(0);
};