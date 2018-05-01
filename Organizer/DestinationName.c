#include "includesH.h"
void createSub(char *);
char * pathForPictures(char *filename)//creates the new address for the picture file
{
     char addr[1024]="";//stores the address for the new location of file

    strcat(addr,"Pictures/");//stores Pictures/  inside the address
    strcat(addr,filename);//adds the file name to the loction so we have Pictures/filename.jpg(or png)
    //so we are returning the relative address of where the new file should go
    return strdup(addr);
}
char * pathForDocuments(char *filename)
{
     char addr[1024]="";//stores relative address of new location of file

    strcat(addr,"Documents/");//adds Documents/ to the relative address of where file should be
    strcat(addr,filename);//adds the filename itself to the relative adrress
    //returns Documents/filename.txt
    return strdup(addr);
}
char * pathForMusic(char *filename)
{
     char addr[1024]="";//stores the relative address for the file
    char artist[1024]="";//stores the name of the artist
    char album[1024]="";//stores the name of the album
    char songName[1024]="";//stores the name of the song
    char *token;//used to break the filename into substrings
    char temp[1024]="";//will hold the filename
    strcpy(temp,filename);//copies the filename so as to be used to tokenize it
    token = strtok(temp, "-");//breaks string by -
    strcpy(artist,token);//stores artist name
    strcat(addr,"Music/");//starts creating the rel. addr. by first adding Music/
    strcat(addr,artist);//now added is Music/artistname
    createSub(addr);//creates the subdiretory with the artist name in the Music folder
    token = strtok(NULL,"-");//gets the album name
    strcpy(album,token);//stores album name in char array
    strcat(addr,"/");//appends to address to make Music/artistname/
    strcat(addr,album);//adds the album name to the relative address Music/artistname/albumname
    createSub(addr);//creates subdirectory inside artist name with the album name
    token = strtok(NULL,"-");//gets the song name
    strcpy(songName,token);//stores song name in char array
    strcat(addr,"/");//adds to the address Music/artistname/albumname/
    strcat(addr,songName);//adds album name to complete the relative address
    return strdup(addr);//Music/artistname/albumname/songname
}
char * pathForShow(char * name)
{
    char addr[1024]="";//stores the relative address
    char temp[1024]="";//holds the initial file name before breaking it down
    char season[1024]="";//holds the season of the show
    char showN[1024]="";//holds show name
    char episode[1024]="";//holds the episode number
    char *token;//used to break file name
    strcpy(temp,name);//copies file name into a char array
    token = strtok(temp,"-");//gets the show name
    strcpy(showN,token);//stores show name in char array
    strcat(addr,"Shows/");//adds to the address Shows/
    strcat(addr,showN);//then appends to the addr. Shows/showname
    createSub(addr);//creates the subdirectory in shows with the showname
    token = strtok(NULL,"-");//get the season for the show
    strcpy(season,token);//stores the season in char array
    strcat(addr,"/");//adds to the addr. Shows/showname/
    strcat(addr,season);//now we have Shows/showname/season
    createSub(addr);//creates the season subdirectory inside the showname
    token = strtok(NULL,"-");//gets the episode number
    strcpy(episode,token);//stores it in char array
    strcat(addr,"/");//adds to the addr to get Shows/showname/season/
    strcat(addr,episode);//we now have Shows/showname/season/episode#
    strcat(addr,"-");//appends to get Shows/showname/season/episode#-
    token = strtok(NULL,"-");//gets the episode name
    strcpy(showN,token);//stores episode name into char array
    strcat(addr,showN);//adds to addr to get Shows/showname/season/epidoe#-epidodename
    return strdup(addr);
}
char * pathForMovie(char *name)
{
    char addr[1024]="";//holds relative address
    char temp[1024]="";//holds the file name
    char year[1024]="";//holds the year the movie came out
    char movieT[1024]="";//holds the movie title
    char *token;//used to break file name into substrings
    strcpy(temp,name);//copies file name into char array
    token = strtok(temp,"-");//gets the year for the movie
    strcpy(year,token);//stores the year in char array
    strcat(addr,"Movies/");//creates running addr as Movies/
    strcat(addr,year);//adds to the addr to get Movies/year
    createSub(addr);//creates the specific year subdirectory in the movie directory
    token = strtok(NULL,"-");//gets the movie title
    strcpy(movieT,token);//stores it in char array
    strcat(addr,"/");//now we have Movies/year/
    strcat(addr,movieT);//adds the movie name to the addr to get Movies/year/moviename
    return strdup(addr);
}
char * pathForOther(char *name)
{
    char addr[1024]="";//holds the relative address
    char temp[1024]="";//stores the file name
    strcpy(temp,name);//stores filename in char array
    strcat(addr,"Other/");//creates addr as Other/
    strcat(addr,temp);//adds to the addr to get Other/filename

    return strdup(addr);
}