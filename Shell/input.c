#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *getLine(FILE *stream)
{

    int count=0;
   char c=0;
    char line[1024]="";

   while((c=fgetc(stream))!= '\n' && (c!=EOF))//reads each char until we encounter new line
   {
       line[count]=c;

       count++;
   }

    line[count+1]='\0';//appends null terminating char
    return strdup(line);//returns the line 


}

