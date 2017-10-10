#include <stdio.h>
#include <malloc.h>
#define FIN "replace_digit.in"
#define FOUT "replace_digit.out"


int changeNumber(int n, int a, int b) {

    int x,

        temp = n,

        temp2 = 0;

    int part1, part2, invers = 0, invers2 = 0;   

    while( temp ){
 
       invers = invers * 10 + temp % 10;       

       temp /= 10;
    }

    while( invers ) {

        temp2 = invers % 10;

        if(temp2 == a) invers2 = invers2 * 10 + b;

                 else
                       invers2 = invers2 * 10 + temp2;

        invers/=10;
    }

    return invers2;
};



int main() {

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    int *arr, i; 

    int n, a, b;

    scanf("%d %d %d", &n, &a, &b); 

    arr = (int*)malloc(sizeof(int) * n); 

    for(i = 0; i < n; ++i) {

        scanf("%d", &arr[ i ]);
    }

    for(i = 0; i < n; ++i) {

        printf("%d -> %d\n", arr[ i ], changeNumber(arr[ i ], a, b));
    } 

    free( arr );

    fclose( stdin ); 

return(0);
};
