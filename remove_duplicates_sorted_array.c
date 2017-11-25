/**
 *  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length;
 *  Do not allocate extra space for another array, you must do this in place with constant memory.
 *  References: https://helloacm.com/how-to-remove-duplicates-from-sorted-array-in-cc-constant-memory/
 */
#include <stdio.h>

void bubblesort(int arr[], int n) {

    int finished = 0, swapped, last = n - 1, i; 

    while(!finished) {

           swapped = 0;

           for(i = 0; i < last; ++i) {

               if(arr[i] > arr[i+1]) {

                  int tmp = arr[i];
                      arr[i] = arr[i+1];
                      arr[i+1] = tmp;
                      swapped = 1;   
               }
           }  

           if(swapped) last--;
              else     finished = 1;  
    } 
}

void removeDuplicates(int arr[], int n) {

     int i, 
         k;

     for(i = 1; i < n; ++i) {

         if(arr[i] == arr[i-1]) { //if duplicate

               for(k = i; k < n - 1; ++k) {

                   arr[k] = arr[k+1];
               }

               n--; 
         } 
     } 

     for(i = 0; i < n; ++i) printf("%d ", arr[i]);
};

int main() {

    int arr[] = {1,5,7,8,9,8,7,9,0,1,3}, 
        n = sizeof(arr)/sizeof(arr[0]), i;

        printf("Input Array:\n");
        for(i = 0; i < n; ++i) printf("%d ", arr[i]); 
  
        bubblesort(arr, n); 
   
        printf("\n");

        for(i = 0; i < n; ++i) printf("%d ", arr[i]);

        printf("\nRemove duplicates from sorted array\n");

        removeDuplicates(arr, n);  
     
    return(0);
};