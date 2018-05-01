#include <stdio.h>
#include <stdlib.h>
#include "organizeH.h"
int main(int argc, char *argv[]) {
    if(argc <= 2) // #number of arguments user enters must be at most 2
    {
        if(argc==2)
        {
            toOrganize(argv[1]);//sends the directory specified by the user to be organized
        }
        else
        {
            toOrganize(".");//no argument then the current directory is to be organized
        }
    }
    else
    {
      fprintf(stderr,"Incorrect number of arguments");//throws error if wrong number of arguments
        exit(1);
    }
    return 0;
}