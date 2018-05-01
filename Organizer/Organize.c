#include "includesH.h"
#include "func.h"
int isDot(struct dirent *file)// function to check if file is . or .. file
{
    if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name,"..") == 0)//checks if file is a . or .. file
    {

        return 1;
    } else return 0;
}
int isExecutable(struct dirent *file)//checks if the current file is executable file
{
    if(strcmp(file->d_name, "organizer")==0) //compares file name to the executable file name
    {
        return 1;
    }
    else return 0;
}
int isFolder(struct dirent *file)//check if the file is in fact folder
{
    DIR *fol = opendir(file->d_name);//opening the folder and if error is ENOTDIR then that means it isnt a directory
    if((fol = opendir(file->d_name)) != NULL ) // if directory opens that means it is a folder so we must ignore it
    {
        closedir(fol);
        return 1;
    }
    if(errno == ENOTDIR) // if the file isn't a directory
    {
        return 0;
    }
    else return 1;
}
int isPic(char *extension)//checks to see if the extension if png or jpg because then its a picture
{   //return true when the extension matches a picture extension
    if(strcmp(extension,"jpg")==0 || strcmp(extension, "png") ==0 )//checks for png or jpg extension
        return 1;
    else return 0;
}

int isDoc(char *extension)//checks if extension is docx or txt because then it is a document
{   //return true when the files extension is docx or txt
    if(strcmp(extension,"docx")== 0 || strcmp(extension, "txt")==0)
        return 1;
    else return 0;

}
int isShow(char *extension, char *name)//check if extension is mkv also counts # of hyphens to determine if show or movie
{
    int count = 0;
    int i=0;
    //first checks if extension is mkv because then its either movie or show
    if(strcmp(extension,"mkv")==0)
    {   //then we count the number of hyphen to determine if its a show or movie
        for(i=0; i<strlen(name);i++)
        {
            if(name[i]=='-')
            count++;


        }


        return count;//return the number of hyphens
    }
    else return 0;
}
int isMusic(char *extension)
{
    if(strcmp(extension,"mp3")==0)//checks if extension is mp3 and returns true or 1
        return 1;
    else return 0;

}
char *getExtension(struct dirent *file)
{
    char *ext = strrchr(file->d_name,'.');//gets the last instance of . and then stores it in a char *

    return ext+1;//returns the extension exlcluding the . by moving pointer up by 1
}
void createDir()//creates the inital directories pictures,movies,...
{
    int pic, mov, shows, other, music, doc;
    if((pic = mkdir("Pictures",0700)) != 0)//creates Picture directory with appropriate permission
    {
        if(!(errno == EEXIST))//only throws error if folder doesnt already exist
        {
            perror("Error: ");
            exit(1);
        }
    }
    if((mov = mkdir("Movies",0700)) != 0)// creates movie directory
    {
        if(!(errno == EEXIST))//any error thrown besides if folder exist
        {
            perror("Error: ");
            exit(1);
        }
    }
    if((music = mkdir("Music",0700)) != 0)//creates music directory
    {
        if(!(errno == EEXIST))
        {
            perror("Error: ");
            exit(1);
        }
    }
    if((shows = mkdir("Shows",0700)) != 0)//creates show directory
    {
        if(!(errno == EEXIST))
        {
            perror("Error: ");
            exit(1);
        }
    }
    if((other = mkdir("Other",0700)) != 0)//creates other directory
    {
        if(!(errno == EEXIST))
        {
            perror("Error: ");
            exit(1);
        }
    }
    if((doc = mkdir("Documents",0700)) != 0)//creates documents directory
    {
        if(!(errno == EEXIST))
        {
            perror("Error: ");
            exit(1);
        }
    }

}
void createSub(char *name)// create subdirectory
{
    int cSub;
    if((cSub = mkdir(name,0700)) != 0)//creates a subdirectory with the given name
    {

        if(!(errno == EEXIST))//any error thrown besides if folder already exists
        {
            perror("Error: ");
            exit(1);
        }
    }

}
void toOrganize(char *pathname)
{
    DIR *dp;//used to open directory
    struct dirent *files;//will be used to go through all the files in the directory
    char *Extension;//holds the extension of the filename
    char destFolder[1024]="";//holds the relative path of the current file after moving it into right folder
    char temp[1024];//used to hold the file name before moving it
    if((dp = opendir(pathname)) == NULL) // opens the directory and also error checks to see if any issue opening the directory
    {
        perror("Error: ");
        exit(1);

    }
    if(chdir(pathname)== -1)//move into the directory specified to be organized also error checks
    {
        perror("Error: ");

        exit(1);
    }
    createDir();//creates the initial subdirectories where all the files will be moved into
    while((files = readdir(dp)) != NULL) // loops through directory reading each file in current folder
    {
        if(isDot(files) == 1)//if its . or .. then we ignore it
        {

            continue;
        }
        else
        if(isExecutable(files)==1)//ignores the file if its the executable file organizer
        {
            continue;
        }
        else
        if(isFolder(files)==1)//ignores if the file is a folder
        {
            continue;
        }
        else
        {

            strcpy(temp,files->d_name);//copies names of file to temporary placeholder
            Extension = getExtension(files);//call to get the extension of the filename
            if(isPic(Extension))//if extension is jpg or png
            {

                strcpy(destFolder, pathForPictures(temp));//copies the relative address for new location into char []
                if(rename(temp,destFolder)!= 0)//moves the file from current location to the new location
                    perror("Error: ");

                strcpy(destFolder,"");//clear the address array
            }
            else
            if(isDoc(Extension))//if the files extension is of a document
            {

                strcpy(destFolder,pathForDocuments(temp));//stores the address of new location
                if(rename(temp,destFolder) != 0)//moves the file to the new location
                    perror("Error: ");

                strcpy(destFolder,"");//clears out the address
            }
            else
            if(isMusic(Extension))//if the files extension is of mp3
            {

                strcpy(destFolder,pathForMusic(temp));//stores the address of new location


                if(rename(files->d_name,destFolder) != 0)//moves the file to new location

                        perror("Error: ");

                strcpy(destFolder,"");//clears the address

            }
            else
            if(isShow(Extension,files->d_name)==3)//if files extension is of show
            {

                strcpy(destFolder,pathForShow(temp));//stores new address for the file
                if(rename(files->d_name,destFolder) != 0)//moves file to new address
                    perror("Error: ");

                strcpy(destFolder,"");//clears the address


            }
            else
            if(isShow(Extension,files->d_name)==1)//if file extension is of movie and has 1 '-' indicating its a movie
            {

                strcpy(destFolder,pathForMovie(temp));//stores new address for the file
                if(rename(files->d_name,destFolder) != 0)//moves the file to new address
                    perror("Error: ");

                strcpy(destFolder,"");//clears the address
            }
            else //if file is none of those extension then it belongs in other subdirectory
            {

                strcpy(destFolder,pathForOther(temp));//stores the address for new location for the file
                if(rename(temp,destFolder)!= 0)//moves the file to the new address
                    perror("Error: ");

                strcpy(destFolder,"");//clears address
            }

        }
    }
}
