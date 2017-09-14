/**
 *  Pointer function - how to declare in struct and how it call, see it.
 */

#include <stdio.h>
#include <malloc.h>


typedef struct pair {
        float x, 
              y;
        float (*func)(float, float); 

} Pair;

float Plus(float x, float y) {
      return x + y;
};

float Minus(float x, float y) {
      return x - y;
};

float Mult(float x, float y) {
      return x * y;
};

float Div(float x, float y) {
      return x / y;
};

float print_result(Pair *ob);

int main() {

    Pair *ptr;

    ptr = (Pair*)malloc(sizeof(Pair));  

    char ch;

    do {

        printf("1. Add +\n");
        printf("2. Sub -\n");
        printf("3. Mult *\n");
        printf("4. Div /\n");
        printf("5. QUIT q/\n");

        printf("Enter the operation: ");
        scanf("%c", &ch);
        printf("%c", ch);

        switch( ch ) {

              case '+': 
              printf("\nEnter the numbers: "); 
              scanf("%f %f", &ptr->x, &ptr->y);
              ptr->func = Plus; 
              break;
           
              case '-':
              printf("\nEnter the numbers: "); 
              scanf("%f %f", &ptr->x, &ptr->y);
              ptr->func = Minus; 
              break;

              case '*':
              printf("\nEnter the numbers: "); 
              scanf("%f %f", &ptr->x, &ptr->y);
              ptr->func = Mult; 
              break;

              case '/':    
              printf("\nEnter the numbers: "); 
              scanf("%f %f", &ptr->x, &ptr->y);
              ptr->func = Div; 
              break;

              default: 
              printf("\nInvalid choice");
              break;

              case 'q':
              exit(0); 
        };     

        print_result(ptr);
   
    }while(1);
    
 return(0);
};

float print_result(Pair *ob) {

      float result = ob->func(ob->x, ob->y);

      printf("(%f , %f) = %f\n",ob->x, ob->y, result);  
};
