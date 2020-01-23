#include <stdio.h>
#include <string.h>
#define FIN "text.in"
#define FOUT "text.out"

int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    char line[100];    
    char *delimitators = " \t\n;,.?!/\"\':";
    char *token;

    fin = fopen(FIN, "r");

    fout = fopen(FOUT, "w");

    if(!fin) { 

    	     printf("%s\n", "The Input file not exist!"); 
    	     return 0;
    }    	     
 
    if(!fout) { 

    	     printf("%s\n", "The Output file not exist!"); 
    	     return 0;
    }    	     
 

    while(!feof(fin)) {

           fgets(line, 100, fin);

           token = strtok(line, delimitators);

           while(token != NULL) {

           	     fputs(token, fout);

           	     fputs("\n", fout);

           	     token = strtok(NULL, delimitators);
           }
    } 
     
     fclose(fin);
     fclose(fout);

	return 0;
}
