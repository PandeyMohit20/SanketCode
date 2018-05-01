#include "includesH.h"
#include "shellProt.h"
#include <sys/wait.h>
#define PROMPT "->"
int main(int argc, char **argv)
{
    FILE *fp;
    char *temp="";
    char addr[1024]="";
    if(getcwd(addr,sizeof(addr))==NULL)
    {
          perror("Error: ");
	   exit(1);
     } 
	char **argbuf;
    if(argc==1)//user will be typing
    {
        do{
            printf(PROMPT);
            temp=getLine(stdin);//call to store users command as a string
            
            if(strcmp(temp,"quit")!=0) {//if user typed quit then we stop

		char **temp2 = argbuf;
                

                
		runshell(temp,addr);//sends our shell users command which is a line of words separated by space
		

            }

        }while(strcmp(temp,"quit")!=0);//loops until we encounter quit
      printf("goodbye\n");

    } else
        if(argc==2)//user sends file to read
        {
	   if((fp = fopen(argv[1],"r"))==NULL)//opens users file for reading
	    {
		fprintf(stderr,"Error opening script file\n");
		exit(1);
		} 
		do{
           // printf(PROMPT);
            temp=getLine(fp);//gets the line from the file
            
            if(strcmp(temp,"")!=0&&strcmp(temp,"quit")!=0) {//if the line says quit

		char **temp2 = argbuf;
                

                
		runshell(temp, addr);
		

            }

        }while(strcmp(temp,"")!=0&&strcmp(temp,"quit")!=0);
      printf("goodbye\n");
            
        }
    else //incorrect number of arguments
    {
    fprintf(stderr,"Incorrect # of inputs");
     exit(1);
    }

}

