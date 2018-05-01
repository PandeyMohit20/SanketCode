#include <stdio.h>
#include <string.h>
void archive(char ** filenames, int numFiles, char* archivename)
{
   FILE *arc;//pointer to archive file
    FILE *input;//pointer to be used for each file name
    int len=0;//store size of name

    char nlen;//store size of name for 1 byte storage
    int size=0;//will store size

   arc=fopen(archivename,"wb");//opens archive for writing
    if(arc==NULL) //error check to see if there are any issues opening the file
        fprintf(stderr,"Error opening archive file\n");

    fwrite(&numFiles,sizeof(int),1,arc);//writes the number of files in 4 bytes into the archive
    while (*filenames != NULL) {//loops until there are no more files to copy into the archive

        input=fopen(*filenames,"r");//opens the input file for reading and copying its elements
        if(input==NULL)//error checks to see if there are any issues opening the file
            fprintf(stderr,"Error opening %s\n",*filenames);
        fseek(input,0L,SEEK_END);//goes to end of file to determine size of file
        size=ftell(input);//stores the size of the file
        fseek(input,0L,SEEK_SET);//resets the offset to the beginning of the file


        len = strlen(*filenames);//stores the length of the filename
        nlen=len;//stores the length in 1 byte

        fwrite(&nlen,1,1,arc);//writes the length of the filename in 1 byte
        fwrite(*filenames,len+1,1,arc);//writes the filename + 1 byte for \0 into the archive
        fwrite(&size,sizeof(int),1,arc);//writes in 4 bytes the size of the file into the archive

        while(!feof(input))//loops until we have reached the end of the file
        {
            char buff[size];//store the contents of the file

            int read = fread(buff,1,size,input);//stores the number of elements read in


            fwrite(buff,1,read,arc);//writes into the archive the contents of file

        }
        filenames++;//moves onto the next file name from the user
    }




}

void unarchive(char * archivefile)
{
  FILE *archive;//pointer to archive file
    FILE *ip;//pointer to input files
    int numfiles=0;//stores the number of files
    int filelength=0;//stores the length of the file name
    char fileName[256];//stores the name of the file

    int i;//used to iterate through the archive
    int content;//stores the size of the sile
    archive=fopen(archivefile,"rb");
    if(archive==NULL)//error checks if there is trouble opening archive
        fprintf(stderr,"Error opening %s\n",archivefile);
    fread(&numfiles,sizeof(int),1,archive);//reads in the number of files in archive and stores it in a variable


    for(i =0; i<numfiles;i++)
    {
        filelength=fgetc(archive);//stores the size of file name from the archive

        fread(fileName,filelength+1,1,archive);//stores the file name from the archive into char array
        ip=fopen(fileName,"w");//opens file for writing
        if(ip==NULL)//error checking to see if issues opening file
            fprintf(stderr,"Error opening %s\n",fileName);
        fread(&content,sizeof(int),1,archive);//stores the size of the file into variable

        char fileContents[content];//creates a char array the size of the file
        fread(fileContents,content,1,archive);//stores the contents from the archive into the array

        fwrite(fileContents,content,1,ip);//writes the contents from the archive into the file

    }




}