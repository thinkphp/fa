#include <stdio.h>
#define MAXN 60001

short sieve[ MAXN ];

int main() {

    unsigned i,
             j,
             n;

    printf("n = ");

    scanf("%d", &n);

    memset(sieve, 1, sizeof( sieve )); 

    for(i = 2; i <= n * n; ++i) {

        if( sieve[ i ] ) {

            j = 2;

            while( i * j <= n) {

                   sieve[ i * j ] = 0;

                   j++;
            }  
        }
    }

    for(i = 2; i <= n ; ++i) 

        if(sieve[ i ]) printf("%d ", i); 

 return(0);
}