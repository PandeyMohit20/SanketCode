#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "createProt.h"
int main(int argc, char **argv)
{
   if(argc==3 || argc==4)//checks if valid num of arg
   {
       if(argc==3)
       {
           if(strcmp(argv[1],"-f")==0)//if user wants to create file
           {
               cFile(argv[2]);
           }
           else
            if(strcmp(argv[1],"-d")==0)//create a directory
            {
                cDir(argv[2]);
            }
            else //invalid flag for the given num of arg
            {
                fprintf(stderr,"Incorrect flag\n");
                exit(1);
            }
       }
       else
       {
           if(strcmp(argv[1],"-h")==0)//create hard link
           {
               cHardLink(argv[2],argv[3]);
           }
           else
           if(strcmp(argv[1],"-s")==0)//create soft link
           {
               cSoftLink(argv[2],argv[3]);
           }
           else//invalid flag for given num of arg
           {
               fprintf(stderr,"Incorrect flag\n");
               exit(1);
           }
       }

   }
    else//invalid num of arg
   {
       fprintf(stderr,"Illegal number of arguments\n");
       exit(1);
   }



   return 0;
}

