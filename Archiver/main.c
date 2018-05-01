#include <stdio.h>
#include <string.h>

#include "cuheader.h"
#include "vlheader.h"
#include <stdlib.h>
int main(int argc, char *argv[])//reads input from the command line
{
    int numF=0;//will store the number of files entered by the user

    char **fileN;//will store the list of file names entered by user
    if(argc<=1)
    {

        fprintf(stderr,"Illegal number of arguments\n");
        exit(1);
    }
    if(strcmp(argv[1],"-a")==0)
    {
        if(argc>=4) {

            printf("Creating archive\n");
            fileN=&argv[3];//stores everything after the archive name
            numF=argc-3;//calculates the number of files the user entered

            archive(fileN,numF,argv[2]);//call the function to create an archive

        }
        else // error printed if user wrote 3 or less arguments
        if(argc==3)//if no files mentioned then error statement is printed
        {
            fprintf(stderr,"No input files specified\n");
            exit(1);
        }
        else {
            fprintf(stderr, "Illegal number of inputs\n");
            exit(1);
        }

    }
    else
    if(strcmp(argv[1],"-u")==0)
    {
        if(argc==3) {
            printf("unpacking archive\n");
            unarchive(argv[2]);//unpacks the archive mentioned

        }
        else //prints error if wrong nunber of inputs
        {
            fprintf(stderr, "Illegal number of inputs\n");//number of inputs exceeds the amount needed therefore illegal number of inputs
            exit(1);
        }
    }
    else
    if(strcmp(argv[1],"-l")==0)
    {
        if(argc==3) {
            printf("Print to stdout\n");
            ArchiveInfo(argv[2]);//prints to the screen the stats of each file in archive
        }
        else // error if user did not enter 3 arguments
        {
            fprintf(stderr, "Illegal number of inputs\n");//number of inputs exceeds the amount needed therefore illegal number of inputs
            exit(1);
        }
    }
    else
    if(strcmp(argv[1],"-v")==0)
    {
        if(argc>=4) {
            printf("Verifying...\n");
            fileN=&argv[3];
            numF=argc-3;
            Verify(fileN,numF,argv[2]); //verifies the contents of the archive
        }
        else {
            fprintf(stderr,"Illegal number of inputs\n");//number of inputs exceeds the amount needed therefore illegal number of inputs
            exit(1);
        }
    }
    else {
        fprintf(stderr, "Illegal flag\n");//number of inputs exceeds the amount needed therefore illegal number of inputs
        exit(1);
    }










    return 0;


}