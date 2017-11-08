/**
 * 
 */
#include <stdio.h>
#define SIZE 100

int main() {

    int i,n,vec[SIZE], k = 0, finished = 0, swapped;  

    printf("n=");
    scanf("%d", &n);
      
    
    while(n) {
     vec[k++] = n%10; 
     n /= 10;     
    }       

    int size = k; 

    while(!finished) {

           swapped = 0;

           for(i = 0; i < size-1; i++) {

               if(vec[i] > vec[i+1]) {

                     int aux = vec[i];vec[i] = vec[i+1]; vec[i+1] = aux;

                     swapped = 1;                  
               } 
           }

           if(swapped) size--;

                 else finished = 1;           
    }    

    int q = 0;
          
    for(i = 0; i < k; ++i) {

        q = q*10 + vec[i]; 
    }

    printf("%d", q);

 return(0);
};