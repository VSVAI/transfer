#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
     fputc("", fptr);
     read(argv[1],argv[2]);
   fclose(fptr);
   return 0;
}


void read(char *html,char *output_file){
     printf(html);
     char data[100];
     char tags[10][5] = {"html", "title", "body","h1","h2","h3","h4","h5","h6","p"} ;
     char line[150];
     FILE *rptr;
     if ((rptr = fopen(html,"r")) == NULL){
          printf("Error! read file not found");
          exit(1);
     }
     
     while(fgetc(rptr) !=  EOF){
          fgets(data,100, rptr);
          for (int i=0;i<10;i++){
               if(strstr(data,tags[i])){

               write(replaceWord(strstr(data,tags[i]),tags[i]," "),output_file);
               }
          }
     }

     fclose(rptr);
}



void write(char *output,char *output_file){
     int j=0,count=0;
     char c ='60';
     char d = '62';

//  for (j = 0; output[j] != '\0'; j++){
//           printf(output[j]);
//           if(output[j]==c && output[j+2]==d){
//              output=replaceWord(output, output[j+1],"");
//           }
//      }
     output=replaceWord(output,"<","");
     output=replaceWord(output,">","");
     output=replaceWord(output,"/","");
     output=replaceWord(output,"  ","");


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