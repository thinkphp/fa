#include <stdio.h>
#define SIZE (sizeof(int) * 8)

int dec2bin(int num) {

    int i; 

    for(i = SIZE - 1; i >= 0; i--) {

        printf("%d", (num>>i&1));
    }

    printf("\n");
};

int _dec2bin(int num) {

    int i, 
        flag = 0; 

    for(i = SIZE - 1; i >= 0; i--) {
         
        if((num>>i)&1 == 1) flag = 1;

        if(flag) printf("%d", (num>>i&1));
    }

    printf("\n");
};

int main() {

 int num;

 scanf("%d", &num);
 dec2bin(num);
 _dec2bin(num);

 return(0);  
};