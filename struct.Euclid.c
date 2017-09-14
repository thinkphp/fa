#include <stdio.h>
#include <malloc.h>

struct Pair {
       int a, 
           b;
       int (*euclid)(struct Pair*);
};

int gdc(struct Pair *p) {

    while(p->b != 0) {

          int tmp = p->b;
          p->b = p->a % p->b;
          p->a = tmp;
    }
    return p->a; 
};

int main() {

    struct Pair *p = (struct Pair*)malloc(sizeof(struct Pair));

                 p->a = 40;

                 p->b = 20;

                 p->euclid = &gdc;  


    printf("%d", p->euclid(p));
           
return(0);
}