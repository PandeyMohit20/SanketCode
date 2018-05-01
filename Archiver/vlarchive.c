#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sizeheader.h"
void ArchiveInfo(char * archivefile)
{
    FILE *archive;//pointer to archive file

    int numfiles=0;//stores the number of files
    int filelength=0;//stores the size of file name
    char fileName[256];//stores file name
    int size=0;//stores the size of archive

    int i;//used to loop through archive
    int content;//store size of each file in the archive
    archive=fopen(archivefile,"rb");
    if(archive==NULL)//error checking to see if any issues opening file
        fprintf(stderr,"Error opening %s\n",archivefile);
    size=getSize(archive);//calculates the size of the archive
    printf("Size of Archive is: %d\n",size);//prints the size of the archive itself
    fread(&numfiles,sizeof(int),1,archive);//stores number of files in archive
    printf("Number of files: %d\n",numfiles);//prints the number of files in archive



    for(i =0; i<numfiles;i++)
    {
        filelength=fgetc(archive);//stores the size of file name

        fread(fileName,filelength+1,1,archive);//read the file name from archive and store it in array

        fread(&content,sizeof(int),1,archive);//reads the size of that file from the archive
        printf("File Name: %s \t File Size: %d\n",fileName,content);//prints the name and size of each file
        char fileContents[content];//array to store contents from archive
        fread(fileContents,content,1,archive);//write content from archive into file


    }




}

void Verify(char ** filenames, int numfile, char * archiveN)
{
  int i=0;//iterate through archive
  FILE *arcName;//pointer to archive
    FILE *ip;//pointer to input files
    char c=0;
    int length=4;//will store the archive expected size
    int length2=0;//will store the actual size of archive
    char fileN[256];//store the name of file
    int contentS=0;//store the size of each file
    int nF=0;//store number of files
    arcName=fopen(archiveN,"rb");
    if(arcName==NULL)//error checking to see if issues opening file
        fprintf(stderr,"Error opening %s\n",archiveN);
     for(i;i<numfile;i++)//iterate to calculate the expected size of archive
     {
         ip=fopen(*filenames,"r");//opens input file
         if(ip==NULL)//error checks
             fprintf(stderr,"Error opening input file");
         length++;//increments size of archive by 1 byte for storing the size of file name
         length = length + strlen(*filenames)+1;//increment by size of filename + 1 for the storage of filename
         length=length+4;//increments by 4 bytes for the storage of size of content
         fseek(ip,0L,SEEK_END);//calculates the size of the input file
         length=length+ftell(ip);//increments by the size of the file for storage of the contents of file
         filenames++;//moves to the next input file


     }
    printf("Expected Size: %d\n",length);// prints the running total of expected size of archive
    filenames=filenames-numfile;//resets pointer to beginning

    fseek(arcName,0L,SEEK_END);//calculates the actual size of archive
    length2=ftell(arcName);
    printf("Actual Size: %d\n",length2);//prints the actual archive size
    if(length!=length2)//if the size archive actual size is different than expected size
    {
        printf("Missing %d bytes\n",(length-length2));//prints the difference in expected size and actual size
        exit(1);
    }
    else //if the size of the actual and expected are same
    {
        fseek(arcName,0L,SEEK_SET);//goes to beginning of archive
        fread(&nF, sizeof(int),1,arcName);
        if(nF!=numfile) {//checks if the number of files is stored properly
            printf("Data corrupted\n");

            exit(1);
        }
        for(i=0;i<numfile;i++)//loops through archive to determine accuracy of archive
        {
            ip=fopen(*filenames,"r");//opens input file
            if(ip==NULL)//error checking
                fprintf(stderr,"Error opening input file");
            fread(&c,1,1,arcName);//reads from the archive the length of the file name
            length=c;//stores size of file name as integer
            if(length!=strlen(*filenames))//compare length of file name from archive to the actual size
            {
                printf("Data corrupted.1\n");

                exit(1);
            }
            fread(fileN,length+1,1,arcName);//read the name of the file
            if(strcmp(fileN,*filenames)!=0)//compares the name of file with the name in the archive
            {
                printf("Data corrupted\n");
                exit(1);
            }
            fread(&contentS, sizeof(int),1,arcName);//reads the size of the file
            length2=getSize(ip);//gets the size of file
            if(contentS!=length2)//compares the size of file to the one written in archive
            {
                printf("Data corrupted\n");

                exit(1);
            }
            char buff1[contentS];//stores contents from archive of the corresponding file
            char buff2[length2];//stores contents of the file
            fread(buff1,contentS,1,arcName);//read contents from archive and stores it in array
            fread(buff2,length2,1,ip);//reads contents from file and stores it in array
            for(i=0;i<length2;i++)//iterate to compare the contents of archive with file
            {
                if(buff1[i]!=buff2[i])//compares byte by byte the archive contents with corresponding file
                {
                    printf("Data corrupted\n");
                    exit(1);
                }
            }

            filenames++;//moves to next file
        }

    }
    printf("Verified\n");//if program never exited than the archive is accurate




}