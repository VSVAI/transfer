#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[2])
{
   if( argc == 3 ) {
        printf("2 arguments supplied. good\n");
   }
   else if( argc == 2 ) {
        printf("1 arguments supplied. good\n");
   }
   else if( argc > 3 ) {
        printf("Too many arguments supplied.\n");
   }
   else {
        printf("One argument expected.\n");
   }
   read(argv[1]);
   write(argv[2]);
   return 0;
}

void read(char *html){
     printf(html);
     char data[100];
     char tags[10][5] = {"<html>", "<title>", "<body>","<h1>","<h2>","<h3>","<h4>","<h5>","<h6>","<p>"} ;
     char backtags[10][5] = {"</html>", "</title>", "</body>","</h1>","</h2>","</h3>","</h4>","</h5>","</h6>","</p>"} ;
     FILE *rptr;
     if ((rptr = fopen(html,"r")) == NULL){
          printf("Error! read file not found");
          exit(1);
     }
     while(fgetc(rptr) !=  EOF){
          fgets(data,100, rptr);
          for (int i=0;i<10;i++){
               if(strstr(data,tags[i]))
               printf(" \n %s",strstr(data,tags[i]));
               }
          }

     fclose(rptr);
     return 0;
}



void write(char *output){
     printf("\n ");
     printf(output);
     int i;
        FILE * wptr;
        char fn[50];
        char str[] = "Guru99 Rocks\n";
        wptr = fopen(output, "w"); // "w" defines "writing mode"
        for (i = 0; str[i] != '\n'; i++) {
            /* write to file using fputc() function */
            fputc(str[i], wptr);
        }
     fclose(wptr);
}