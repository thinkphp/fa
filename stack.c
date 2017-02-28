#include <stdio.h>
#include <malloc.h>

typedef struct {

    char name[ 20 ];

    int code;

} Data;

typedef struct {
 
  Data elem;

  struct Stack *next;
    
} Stack;

void create(Stack **s) {

     int i,
         n;

     Stack *st;

     *s = NULL;

     printf("How many elements do you want to enter?");

     scanf("%d", &n);

     for(i = 1; i <= n ; ++i) {

         st = (Stack*)malloc(sizeof(Stack));  

         printf("Name=");

         scanf("%s", st->elem.name);

         printf("code=");

         scanf("%d", &st->elem.code);

         st->next = *s; 

         *s = st;
     }
}

void display(Stack *stack) {

     while( stack ) {

            printf("( %s, %d )\n", stack->elem.name, stack->elem.code);

            stack = stack->next;  
     }
}

int main() {

 Stack *stack;

 create(&stack);

 display( stack );

 return 0;
}