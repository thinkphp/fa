#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void *readMatrix(int l,int c) {

      srand (time(NULL));

      int (*mat)[10] = new int[10][10];

     for(int i = 0; i < l; ++i) {

         for(int j = 0; j < c; ++j) {

                 int c = rand()%10;

                 mat[ i ][ j ] = c;
         } 
     } 

      return mat;  
}

void *sumMatrix(int (*mat1)[10], int (*mat2)[10], int l,int c) {

      srand (time(NULL));

      int (*mat)[10] = new int[10][10];

     for(int i = 0; i < l; ++i) {

         for(int j = 0; j < c; ++j) {

                 int c = rand()%10;

                 mat[ i ][ j ] = mat2[ i ][ j ] + mat2[ j ][ j ];
         } 
     } 

      return mat;  
}

void printMatrix(int (*mat)[10],int l,int c) {
    
     cout<<"Matrix"<<endl;
     for(int i = 0; i < l; ++i) {

         for(int j = 0; j < c; ++j) {

                 cout<<mat[i][j]<<" "; 
         } 

                 cout<<endl;
     } 
}

int main( void ) {

    int (*adr1)[10], (*adr2)[10], (*sum)[10];
    int l = 3, c = 3;
     
    adr1 = (int(*)[10])readMatrix(3,3);
    adr2 = (int(*)[10])readMatrix(3,3); 

    printMatrix(adr1, l, c);
    printMatrix(adr2, l, c);
    sum = (int(*)[10])sumMatrix(adr1, adr2, l, c); 
    printMatrix(sum, l, c);
    return(0); 
};