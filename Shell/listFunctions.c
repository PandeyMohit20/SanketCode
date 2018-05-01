#include "includesH.h"
int isHidden(char *name) //returns true if file starts with . meaning hidden
{
    if(name[0]=='.')
        return 1;
    else return 0;

}

void FileNames(char *pathname)
{

    DIR *dp;
    struct dirent *files;
    

    if((dp=opendir(pathname))==NULL)//open directory
    {
	
        perror("Error: ");
        exit(1);
    }
    if(chdir(pathname)== -1)//move into the directory
    {
        perror("Error: ");

        exit(1);
    }
    while((files = readdir(dp)) != NULL) // loops through directory reading each file in current folder
    {
        if(isHidden(files->d_name))//if hidden file
            continue;
         printf("%s\n",files->d_name);//prints file names that are not hidden files

    }


}
void fileInfos(char *pathname)
{
    DIR *dp;
    struct dirent *files;
    int file;
    struct stat fileinfo;
    if((dp=opendir(pathname))==NULL)//open directory
    {
        perror("Error: ");
        exit(1);
    }
    if(chdir(pathname)== -1)//move into the directory
    {
        perror("Error: ");

        exit(1);
    }
    while((files = readdir(dp)) != NULL) // loops through directory reading each file in current folder
    {
        if(isHidden(files->d_name))//if hidden file
            continue;
        if((file=open(files->d_name,O_RDONLY))<0)//error check if issue opening
        {
            perror("Error: ");
            exit(1);
        }
        if(fstat(file,&fileinfo)<0)//calling fstat to get file info
        {
            perror("Error: ");
            exit(1);
        }
        
        //prints the files info such as size and inode number
        printf("%s\t\t%d\t\t%o\t\t%d\n",files->d_name,fileinfo.st_size,fileinfo.st_mode,fileinfo.st_ino);
        if((close(file))<0)//close the file
        {
            perror("Error: ");
            exit(1);
        }
    }

}
void hFiles(char *pathname)
{
    DIR *dp;
    struct dirent *files;
    if((dp=opendir(pathname))==NULL)//open directory
    {
        perror("Error: ");
        exit(1);
    }
    if(chdir(pathname)== -1)//move into the directory
    {
        perror("Error: ");

        exit(1);
    }
    while((files = readdir(dp)) != NULL) // loops through directory reading each file in current folder
    {
        if(!(isHidden(files->d_name)))//if hidden file
            continue;
        printf("%s\n",files->d_name);//print hidden files names

    }

}