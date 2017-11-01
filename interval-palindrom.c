#include <stdio.h>

int main() {

    int a,//intervals
        b, 
        i,//iterator
        c,//copy of number
        p;//palindrom

       

    scanf("%d %d", &a, &b);

    for(i = a; i <= b; ++i) {

        c = i;

        p = 0;

        while( c ) {

              p = p * 10 + c % 10;

              c /= 10; 
        }         

        if(p == i) {

           printf("%d\n", i);
        }
    }    

 return(0);
};