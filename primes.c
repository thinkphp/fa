#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define FIN "primes.in"
#define FOUT "primes.out"

int isPrime(int num) {

    int i, isprime = 1;

    if(num == 1) return 0;

    if(num == 2) return 1;

    for(i = 2; i <= sqrt( num ); ++i) {

        if( num % i == 0) { 

            isprime = 0; break; 
        }
    }

    return isprime;
};

int main() {

    int i, n; 
    int *arr;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; ++i) scanf("%d", &arr[ i ]);

    for(i = 0; i < n; ++i) {

        if(isPrime( arr[ i ] )) {

             printf("%d -> %s",arr[ i ], "YES");

        } else {

             printf("%d -> %s",arr[ i ], "NO");
        }

        printf("\n");
    }

    fclose( stdin );

    free(arr);
 
    return(0);
}