#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./html_parser.h"
char* replaceWord(const char* s, const char* oldW,
                  const char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
    // Making new string of enough length
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }
    result[i] = '\0';
    return result;
}
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
     FILE *fptr;
     fptr = fopen(argv[2], "w");
    
     Read(argv[1],argv[2]);
   fclose(fptr);
   return 0;
}


void Read(char *html,char *output_file){
     char data[100];
     char tags[20][8] = {"<html>", "<title>", "<body>","<h1>","<h2>","<h3>","<h4>","<h5>","<h6>","<p>","</html>", "</title>", "</body>","</h1>","</h2>","</h3>","</h4>","</h5>","</h6>","</p>"} ;

     FILE *rptr;
     if ((rptr = fopen(html,"r")) == NULL){
          printf("Error! read file not found");
          exit(1);
     }
     while(fgetc(rptr) !=  EOF){
          fgets(data,100, rptr);
          for (int i=0;i<20;i++){
               if(strstr(data,tags[i])){

               Write(replaceWord(strstr(data,tags[i]),tags[i]," "),output_file);
               }
          }
     }

     fclose(rptr);
}

void Write(char *output,char *output_file){
     char tags[10][8] = {"</html>", "</title>", "</body>","</h1>","</h2>","</h3>","</h4>","</h5>","</h6>","</p>"} ;
     for (int i=0;i<10;i++){
               if(strstr(output,tags[i])){
               output=replaceWord(output,tags[i]," ");
               output=replaceWord(output,"<","");
               output=replaceWord(output,">","");
               output=replaceWord(output,"/","");
          }
     }

     int i;
        FILE * wptr;
        char fn[50];
        char str[] = "Guru99 Rocks\n";
        wptr = fopen(output_file, "a"); // "w" defines "writing mode"
        for (i = 0; output[i] != '\0'; i++) {
            /* write to file using fputc() function */
            fputc(output[i], wptr);
            }
     printf(output);
     fclose(wptr);
}