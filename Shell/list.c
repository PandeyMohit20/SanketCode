#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcProt.h"
int main(int argc, char **argv)
{
    if(argc>=1 && argc<=3)//checks if correct num of arg
    {
            if(argc==1)//current directory
                FileNames(".");
            else
            {
                if(argc==2)//working with current directory with given flag or list pathname
                {
                    if(argv[1][0]!='-')//specified a directory
                        FileNames(argv[1]);
                    else
                        if(argv[1][1]=='h')//if user wants hidden files
                            hFiles(".");
                        else
                        if(argv[1][1]=='i')//user wants info on files
                            fileInfos(".");
                        else {//invalid flag
                            fprintf(stderr, "Illegal flag\n");
                            exit(1);
                        }
                }
                else // working with specified directory
                {
                    if(strcmp(argv[1],"-i")==0)
                        fileInfos(argv[2]);
                    else
                        if(strcmp(argv[1],"-h")==0)
                            hFiles(argv[2]);
                    else
                        {
                            fprintf(stderr,"Illegal flag\n");
                            exit(1);
                        }
                }


            }
            


    }
    else//invalid num of arg
    {
        fprintf(stderr,"Illegal number of inputs: %d\n",argc);
        exit(1);
    }
    return 0;
}