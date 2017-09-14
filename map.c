/**
 *  The question is: What are function pointers used for and how would I use them?
 *  A simple case is like this: 
 * 
 *    You have an array of operations according to you business logic. You have  
 *    a hashing function that reduces an input problem to one of the business logic functions.
 *    A clean code would have an array an array of function pointers, and your program 
 *    will deduce an index to that array from the input and call it.
 *    One quit common use case is a callback function. For example if you load
 *    something  from a DB you can implement your loading function so that it 
 *    reports the progress to a callback function. This can be done with function pointers.
 *    
 *    Let's do a map-like function for C.
 */

#include <stdio.h>

int cube(int i) {

    return i*i*i;
};

int mult(size_t i, int j) {

    return i * j;
};


void apply(int *arr, size_t len, int (*fnPtr)(int)) {

     for(size_t i = 0; i < len; ++i) {

         arr[i] = fnPtr(arr[i]);
     }             
};

void apply_enumerate(int *arr, size_t len, int (*fnPtr)(size_t, int)) {

     for(size_t i = 0; i < len; ++i) {

         arr[i] = fnPtr(i, arr[i]);
     }             
};


void print_array(int *arr, size_t len, char *sep) {

     if(sep == NULL) sep = ", ";

     printf("%d", *arr);

     for(size_t i = 1; i < len; ++i) printf("%s%d", sep, arr[i]); 

     printf("\n"); 
};

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

int main() {

    int arr[5] = {1,2,3,4,5};
    print_array(arr, ARRAY_SIZE(arr), NULL);
    apply(arr, ARRAY_SIZE(arr), cube);
    print_array(arr, ARRAY_SIZE(arr), NULL);
    apply_enumerate(arr, ARRAY_SIZE(arr), mult);
    print_array(arr, ARRAY_SIZE(arr), NULL);

 return(0);
};