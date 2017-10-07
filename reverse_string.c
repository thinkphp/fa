#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char* reverse(char *s) {

      int n; 

      for(n = 0; s[n] != '\0'; n++);

      int start = 0, 
          end = n - 1; 

      while(start < end) {

            char tmp = *(s+start);
                 *(s+start) = *(s+end);
                 *(s+end) = tmp;
                 start++; end--; 
      } 

      *s = toupper(*s);

      return s;
};


int main() {

    Node *head = NULL;
    char str[] = "nairda";
    printf("%s", reverse(str));

 return(0);   
};