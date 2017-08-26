/**
 *************
 * Set Theory
 * *********** 
 * 1. Intersection (In Mathematics. the intersection of two sets A and B is the set that contains all elements of A that also belong to B)
 * 2. Union (the union of a collection of sets is the set of all elements in the collection)
 * 3. Diff (A \ B) the elements that not contains B
 */
#include <stdio.h>
#define SIZE 50

typedef struct set {

       short card,
             S[SIZE];  
} Set;

void read(Set *p) {

     int i;

     printf("Card ->");
     scanf("%d", &p->card);

     printf("Give the elements ->");
     for(i = 0; i < p->card; ++i) scanf("%d",&p->S[i]);
};

int apart(Set A, short item) {

    int i;

    for(i = 0; i < A.card; ++i) 

        if(A.S[i] == item) return 1; 

    return 0;
};

void printSet(Set X) {

     int i;

  if(X.card > 0) {

     for(i = 0; i < X.card - 1; ++i) 

         printf("%d, ", X.S[i]);

     printf("%d", X.S[X.card-1]);

   } else {
 
     printf("Empty");

   }
};

int main() {

    int i;
    Set A, B, R, I, D;

    read(&A);

    read(&B);

    R = A;

    I.card = D.card = 0;
     
    for(i = 0; i < B.card; ++i)

        if(apart(A, B.S[i])) I.S[I.card++] = B.S[i];

                 else
                             R.S[R.card++] = B.S[i];

    for(i = 0; i < A.card; ++i)

        if(!apart(B, A.S[i])) D.S[D.card++] = A.S[i];   
                     

    printf("\nUnion (A U B)-> ");
    printSet(R);

    printf("\nIntersect (A ^ B)-> ");
    printSet(I);

    printf("\nDiff (A / B)-> ");
    printSet(D);


 return(0);
};