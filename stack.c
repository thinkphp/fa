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

void push(Data data, Stack **stack) {

     Stack *q = (Stack*)malloc(sizeof(Stack));

            q->elem = data;

            q->next = *stack;

            *stack = q;
}

void pop(Stack **stack) {

     Stack *q = *stack;

            *stack = (*stack)->next;

            free(q); 
}

Data top(Stack **stack) {

     Data theTop;

     if( isEmpty(*stack) == 0) return;

     theTop = (*stack)->elem;

     Stack *st = *stack;

          (*stack) = (*stack)->next;

     free( st );

     return theTop; 
}

void display(Stack *stack) {

     while( stack ) {

            printf("( %s, %d )\n", stack->elem.name, stack->elem.code);

            stack = stack->next;  
     }
}

int isEmpty(Stack *stack) {

    if(stack == NULL) return 0;

         else return 1;
}

int main() {

 Stack *stack;
 Data ob;

 //create the object abstrack Stack
 create(&stack);
 //display the Stack
 display( stack );

 //add a object into Stack and display it
 printf("Name=");
 scanf("%s", ob.name);
 printf("Code=");
 scanf("%d", &ob.code);
 push(ob, &stack);
 display(stack);

 //pop Stack
 pop(&stack);
 printf("Pop()\n");
 //display after this Pop
 display(stack);
 
 //get the Top from Stack
 ob = top(&stack);
 printf("Top=(%s,%d)\n", ob.name, ob.code);

 display(stack);

 //add a object into Stack and display it
 printf("Name=");
 scanf("%s", ob.name);
 printf("Code=");
 scanf("%d", &ob.code);
 push(ob, &stack);
 display(stack);


 return 0;
}