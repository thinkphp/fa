/**
 * @description  Comb Sort is mainly an improvement over Bubble Sort. Bubble Sort always compares adjacent keys. So
 * all inversions are removed one by one. Comb sort improves on Bubble Sort by using gap of size more than 1. The gap
 * starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1. The shrink factor
 * has been empirically found to be 1.3 (by testing on over 200.000 random lists). Although, it works better than Bubble on average, worst case remains O (n^2).
 * @license MIT 
 */
#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

void combSort(int arr[], int n) {

     //init gap
     int gap = n,

         swapped = 1, 
 
         i;

         while(gap != 1 || swapped == 1) {

               if(gap > 1) gap = (gap * 10) / 13;//shrink factor

               swapped = 0;

               for(i = 0; i + gap < n; ++i) {

                       if(arr[ i ] > arr[ i + gap ]) {

                          int tmp = arr[ i ];

                              arr[ i ] = arr[ i + gap ];

                              arr[ i + gap ] = tmp;

                              swapped = 1;
                       }
               }        
         }
};

int main() {

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    int arr[SIZE],
        i, 
        n;

    scanf("%d", &n);

    for(i = 0; i < n; ++i) scanf("%d", &arr[ i ]);       

    combSort(arr, n);

    for(i = 0; i < n; ++i) printf("%d ", arr[ i ]);

 return(0);
};