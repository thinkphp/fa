#include <stdio.h>
#define SIZE 50
#define FIN "matrix.in"
#define FOUT "matrix.out"

int mat[ SIZE ][ SIZE ], n;

void readMatrix() {

     int i, 
         j;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; ++i) {

         for(j = 0; j < n; ++j) {

             scanf("%d", &mat[i][j]);
         } 
     } 
};

int sum(int n, int line) {

    int s = 0, j;

    for(j = 0; j < n; ++j) {

        s += mat[line][j];
    } 

    return s;
}

void printMatrix() {

     int i, 
         j;

     freopen(FOUT, "w", stdout);


     for(i = 0; i < n; ++i) {

         for(j = 0; j < n; ++j) {

             printf("%d ", mat[i][j]);
         } 

         printf("\n"); 
     } 
};

void swapLines(int i, int j) {
     int aux, 
         k;

         for(k = 0; k < n; ++k) {
             aux = mat[i][k];
             mat[i][k] = mat[j][k];
             mat[j][k] = aux;    
         } 
};

void sortLines() {

    int i,size;
    int finished = 0, swapped; 
    size = n; 
    while(!finished) {
           swapped = 0;
           for(i = 0; i < size - 1; ++i) {
               if(sum(n, i) > sum(n,i+1)) {
                  swapLines(i, i + 1);
                  swapped = 1; 
               }  
           }

           if(swapped) size--;
               else finished = 1;
    }

};

int main() {

    readMatrix();
    sortLines(); 
    printMatrix(); 

 return(0);
};