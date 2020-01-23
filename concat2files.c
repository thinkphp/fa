#include <stdio.h>

void concat(char name1[20], char name2[20]) {

     char ch;
     FILE *file1, 
          *file2;

     file1 = fopen(name1, "rt");
     file2 = fopen(name2, "at");

     if(!file1) {

        printf("%s\n", "Input File error!");
     }
     
     if(!file2) {

        printf("%s\n", "Output File error!");
     }

     while(file1 && !feof(file1)) {

           ch = fgetc(file1);
           fputc(ch, file2);
     }

     fclose(file1);
     fclose(file2); 
}

int main(int argc, char *argv[])
{
    char *name1 = argv[1],
         *name2 = argv[2];                   

    concat(name1, name2);

	return 0;
}
