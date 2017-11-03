/**
 * Let's read a number. Check if the sum of diametrically oppused digits is constant.
 */

#include <stdio.h>

int main() {

    int n,
        c,//copy to number
        num, //counter
        s; //inverse number
     

    scanf("%d", &n);
     
    num = 0;

    c = n;

    s = 0;
 
    while( c ) {

           s = s * 10 + c % 10;
 
           c /= 10;

           num++;
    } 

    int p, flag;
 
    if( num % 2 == 0 ) {

        p = n % 10 + s % 10;

        flag = 1;

        while( n ) {

               if(p != n % 10 + s % 10) flag = 0;
               
               n /= 10;
               s /= 10;
        }          

        if( flag ) printf("Constant!");

                 else 

                   printf("Not Constant!");
    } else {

       int i = 1, 

           t = (num + 1)/2;

           p = n % 10 + s % 10;

           flag  = 1;      

        while( n ) {
               
               if(i == t) {

                        if((p + p) != n % 10 + s % 10) flag = 0;
                }

                   else {
 
                        if(p != n % 10 + s % 10) flag = 0;
                   }
               
               i++;

               n /= 10;
               s /= 10;
        }          

        if( flag ) printf("Constant!");

                 else 

                   printf("Not Constant!");
                    
    }
  
 return(0);
};