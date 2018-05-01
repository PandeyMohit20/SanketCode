#include "includesH.h"
void cFile(char *pathname)
{
    int fp;
    if((fp=creat(pathname,0640))<0)//creates file with 640 mode
    {
        perror("Error: ");
        exit(1);
    }
}
void cDir(char *pathname)
{
    int fp;
    if((fp=mkdir(pathname,0750))<0)//creates dir with 750 mode 
    {
        perror("Error: ");
        exit(1);
    }
}
void cHardLink(char *oldname,char *newname)
{
    int fp;
    if((fp=link(oldname,newname))<0)//creates a hardlink for the specified file with the specified new name
    {
        perror("Error: ");
        exit(1);
    }
}
void cSoftLink(char *name,char *symname)
{
    int fp;
    if((fp=symlink(name,symname))<0)//creates a symbolic link
    {
        perror("Error: ");
        exit(1);
    }
}