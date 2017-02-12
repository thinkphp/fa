#include <stdio.h>

void turn_into_primes_factors(int n) {

     int count;

     int i = 2;

     do {

        count = 0;

        while(n % i == 0) {

              count++;

              n /= i;
        }  

        if(count!=0) printf("%d^%d\n",i,count); 
                  
        i++;
        
     }while(n != 1);
}

int main() {

 int num;

 printf("N=");
 scanf("%d", &num);

 turn_into_primes_factors( num );

 return(0);
}